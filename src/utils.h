#ifndef UTILS_H
#define UTILS_H
#include <QMap>
#include <QSize>
#include <QtGlobal>

#define _FPS 45;
#define _PLAYER_COUNT 2;

namespace KEYBOARD
{
static constexpr const int KEY_W = 11; //Player1 go Forward
static constexpr const int KEY_A = 20; //Player1 go Left
static constexpr const int KEY_S = 21; //Player1 go Backward
static constexpr const int KEY_D = 22; //Player1 go Right

static constexpr const int KEY_Z = 29; //Capture Screen

static constexpr const int KEY_LEFT  = 37; //Player2 go Forward
static constexpr const int KEY_RIGHT = 38; //Player2 go Left
static constexpr const int KEY_UP    = 39; //Player2 go Backward
static constexpr const int KEY_DOWN  = 40; //Player2 go Right

static const QMap<int, int> KeysMapper =
    {
        {static_cast<int>(Qt::Key_W),  KEY_W},
        {static_cast<int>(Qt::Key_A),  KEY_A},
        {static_cast<int>(Qt::Key_S),  KEY_S},
        {static_cast<int>(Qt::Key_D),  KEY_D},

        {static_cast<int>(Qt::Key_Z),  KEY_Z},

        {static_cast<int>(Qt::Key_Left),   KEY_LEFT},
        {static_cast<int>(Qt::Key_Right),  KEY_RIGHT},
        {static_cast<int>(Qt::Key_Up),     KEY_UP},
        {static_cast<int>(Qt::Key_Down),   KEY_DOWN}
};
}

namespace SCREEN
{
static constexpr const QSize LOGICAL_SIZE  = QSize(160, 100);
static constexpr const QSize CELL_SIZE     = QSize(5 , 5  );
static constexpr const QSize PHYSICAL_SIZE = QSize( LOGICAL_SIZE.width()  * CELL_SIZE.width(),
                                                   LOGICAL_SIZE.height() * CELL_SIZE.height());
}
#endif // UTILS_H
