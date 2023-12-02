/*************************************************************
 * 1. Name:
 *      Team 7 Daniel Carr & Cayden Lords
 * 2. Assignment Name:
 *      Lab 07: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "test.h"
#include "bullet.h"
#include "howitzer.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(howitzer.getAngle())
   {
      // Set the horizontal position of the howitzer. This should be random.
      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 5.0);

      // Generate the ground and set the vertical position of the howitzer.
      ground.reset(ptHowitzer);

      howitzer.setPosition(ptHowitzer.getMetersX(), ptHowitzer.getMetersY());

      // This is to make the bullet travel across the screen. Notice how there are 
      // 20 pixels, each with a different age. This gives the appearance
      // of a trail that fades off in the distance.
      

   }

   Ground ground;                 // the ground
   Position  projectilePath[20];  // path of the projectile
   Position  ptHowitzer;          // location of the howitzer
   Position  ptUpperRight;        // size of the screen
   Angle angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
   Bullet bullet;
   Howitzer howitzer;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight()) {
       double right = pDemo->howitzer.getAngle();
       pDemo->howitzer.setAngle((right += 0.05));
   }
   if (pUI->isLeft()) {
       double left = pDemo->howitzer.getAngle();
       pDemo->howitzer.setAngle((left -= 0.05));
   }

   // move by a little
   if (pUI->isUp()) {
       double up = pDemo->howitzer.getAngle();
       pDemo->howitzer.setAngle(up += (up >= 0 ? -0.003 : 0.003));
   }
   if (pUI->isDown()) {
       double down = pDemo->howitzer.getAngle();
       pDemo->howitzer.setAngle( down += (down >= 0 ? 0.003 : -0.003));
   }

   // fire that gun
   if (pUI->isSpace()) {
       
       pDemo->howitzer.fireBullet();
       cout << pDemo->howitzer.getAngle() << endl;
       cout << pDemo->howitzer.getPosition() << endl;
       cout << time << endl;
       cout << pDemo->bullet.getAge() << endl;
       cout << pDemo->bullet.bulletMath() << endl;
       cout << endl;
       for (int i = 0; i < 20; i++)
       {
           pDemo->projectilePath[i].setPixelsX((double)i * 2.0);
           pDemo->projectilePath[i].setPixelsY(pDemo->ptUpperRight.getPixelsY() / 1.5);
       }
       pDemo->bullet = Bullet(pDemo->howitzer.getPosition(), 827, pDemo->howitzer.getAngle(), 0);
       
       //pDemo->time = 0.0;
   }
      

   //
   // perform all the game logic
   //

   // advance time by half a second.
   pDemo->time += 0.5;

   // move the projectile across the screen
   if (pDemo->ground.getElevationMeters(pDemo->projectilePath[0]) < pDemo->projectilePath[0].getMetersY()) {
           Position location = pDemo->bullet.bulletMath();
           double age = pDemo->bullet.getAge();
           pDemo->projectilePath[0].setMetersX(location.getMetersX());
           pDemo->projectilePath[0].setMetersY(location.getMetersY());
           if (pDemo->ground.getTarget().getMetersX() == location.getMetersX() && pDemo->ground.getTarget().getMetersY() == location.getMetersY())
           {
               pDemo->ground.reset(pDemo->ptHowitzer);
           }
       }
   else {
       pDemo->bullet.endMove();
   }
  //
   // draw everything
   //

   ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pDemo->ground.draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pDemo->howitzer.getPosition(), pDemo->howitzer.getAngle(), pDemo->time);

   // draw the projectile
   for (int i = 0; i < 20; i++)
      gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
        << pDemo->bullet.getAge() << "s\n";
   gout << "Location of Bullet"
       << pDemo->projectilePath[0];
}


double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
