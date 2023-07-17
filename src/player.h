#ifndef PLAYER_H
#define PLAYER_H

#include <QThread>
#include "gamescene.h"
#include <QSemaphore>

// GameLogicThread1 클래스 (스레드 1용)
class GameLogicThread1 : public QThread
{
    Q_OBJECT
public:
    explicit GameLogicThread1(GameScene* scene, QObject* parent = nullptr)
        : QThread(parent), m_scene(scene)
    {}

protected:
    void run() override
    {
        while (!isInterruptionRequested()) {
            m_scene->gameLogicThread1Loop();
        }
    }

private:
    GameScene* m_scene;
};

// GameLogicThread2 클래스 (스레드 2용)
class GameLogicThread2 : public QThread
{
    Q_OBJECT
public:
    explicit GameLogicThread2(GameScene* scene, QObject* parent = nullptr)
        : QThread(parent), m_scene(scene)
    {}

protected:
    void run() override
    {
        while (!isInterruptionRequested()) {
            m_scene->gameLogicThread2Loop();
        }
    }

private:
    GameScene* m_scene;
};

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    // ...

    // GameScene에서 추가로 선언된 멤버 변수
    GameLogicThread1 m_gameLogicThread1;
    GameLogicThread2 m_gameLogicThread2;

    // ...

    // GameScene에서 추가로 선언된 멤버 함수
    void gameLogicThread1Loop();
    void gameLogicThread2Loop();

signals:
    void player1KeyPressed(QKeyEvent* event);
    void player1KeyReleased(QKeyEvent* event);
    void player1MousePressed(QGraphicsSceneMouseEvent* event);
    void player1MouseMoved(QGraphicsSceneMouseEvent* event);
    void player1MouseReleased(QGraphicsSceneMouseEvent* event);

    void player2KeyPressed(QKeyEvent* event);
    void player2KeyReleased(QKeyEvent* event);
    void player2MousePressed(QGraphicsSceneMouseEvent* event);
    void player2MouseMoved(QGraphicsSceneMouseEvent* event);
    void player2MouseReleased(QGraphicsSceneMouseEvent* event);

protected:
    // ...

    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    // ...
};

void GameScene::loop()
{
    // ...

    while (m_loopTime > m_loopSpeed) {
        // ...

        // 분할된 게임 로직 스레드에서 게임 로직 처리
        m_gameLogicThread1.start();
        m_gameLogicThread2.start();
        m_gameLogicThread1.wait();
        m_gameLogicThread2.wait();

        // ...

        m_loopTime -= m_loopSpeed;
        resetKeyStatus();
    }
}

void GameScene::gameLogicThread1Loop()
{
    // 플레이어 1의 입력 처리
    handlePlayer1Input(elapsedTime);

    // 게임 로직 처리 (스레드 1)
    // ...

    // 플레이어 1의 게임 객체 그리기 (스레드 1)
    // ...

    // 필요한 경우 시그널을 발생시켜 메인 스레드에서 그래픽 객체를 그리도록 함 (스레드 1)
    // ...
}

void GameScene::gameLogicThread2Loop()
{
    // 플레이어 2의 입력 처리
    handlePlayer2Input(elapsedTime);

    // 게임 로직 처리 (스레드 2)
    // ...

    // 플레이어 2의 게임 객체 그리기 (스레드 2)
    // ...

    // 필요한 경우 시그널을 발생시켜 메인 스레드에서 그래픽 객체를 그리도록 함 (스레드 2)
    // ...
}

void GameScene::handlePlayer1Input(float elapsedTime)
{
    // 플레이어 1의 입력 처리 로직 (스레드 1)
    // ...
}

void GameScene::handlePlayer2Input(float elapsedTime)
{
    // 플레이어 2의 입력 처리 로직 (스레드 2)
    // ...
}

void GameScene::keyPressEvent(QKeyEvent* event)
{
    // 플레이어 1의 키 입력 처리
    emit player1KeyPressed(event);

    // 플레이어 2의 키 입력 처리
    emit player2KeyPressed(event);

    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent* event)
{
    // 플레이어 1의 키 릴리즈 처리
    emit player1KeyReleased(event);

    // 플레이어 2의 키 릴리즈 처리
    emit player2KeyReleased(event);

    QGraphicsScene::keyReleaseEvent(event);
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    // 플레이어 1의 마우스 입력 처리
    emit player1MousePressed(event);

    // 플레이어 2의 마우스 입력 처리
    emit player2MousePressed(event);

    QGraphicsScene::mousePressEvent(event);
}

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    // 플레이어 1의 마우스 이동 처리
    emit player1MouseMoved(event);

    // 플레이어 2의 마우스 이동 처리
    emit player2MouseMoved(event);

    QGraphicsScene::mouseMoveEvent(event);
}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    // 플레이어 1의 마우스 릴리즈 처리
    emit player1MouseReleased(event);

    // 플레이어 2의 마우스 릴리즈 처리
    emit player2MouseReleased(event);

    QGraphicsScene::mouseReleaseEvent(event);
}


#endif // PLAYER_H
