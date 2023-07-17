#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "gamethread.h"
#include "utils.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View();

signals:

private:
    const static int PLAYER_COUNT = 2;
    GameThread* m_gameThread[PLAYER_COUNT];

    // QWidget interface
protected:
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // VIEW_H
