#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QRect>
//https://doc.qt.io/qt-5/animation-overview.html

// ye fk globasls but FFS it's a sadbox
constexpr int ANIM_DUR_TIME = 10000;

// no ownership passed in either case

//  This code will move button from the top left corner of the screen to the position 
//  (250, 250) in 10 seconds (10000 milliseconds). based on ANIM_DUR_TIME
void clown_fiesta1(QPropertyAnimation *animation)
{
  animation->setStartValue(QRect(0, 0, 100, 30));
  animation->setEndValue(QRect(250, 250, 100, 30));
}

//In this example, the animation will take the button to (250, 250) in 8 seconds, and 
//then move it back to its original position in the remaining 2 seconds. The movement 
//will be linearly interpolated between these points.
void clown_fiesta2(QPropertyAnimation *animation)
{
  animation->setKeyValueAt(0, QRect(0, 0, 100, 30));
  animation->setKeyValueAt(0.8, QRect(250, 250, 100, 30));
  animation->setKeyValueAt(1, QRect(0, 0, 100, 30));
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
//    QLabel hello("Hello world!");
//    hello.show();

    QPushButton button("Sample butt");
    button.show();
    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(ANIM_DUR_TIME);
    clown_fiesta2(&animation);
    animation.start();
    
    
    return app.exec();
}
