# ifndef            GAMETHREAD_H
#  define           GAMETHREAD_H

#  include          <QGraphicsScene>
#  include          <QGraphicsView>
#  include          <QElapsedTimer>
#  include          <QTimer>
#  include          <QVector>
#  include          <QPair>
#  include          <QImage>
#  include          <QPixmap>
#  include          <QThread>
#  include          "utils.h"

struct              KeyStatus
{
    bool            m_held = false;
    bool            m_released = false;
};

class               GameScene :
                        public QGraphicsScene
{
    Q_OBJECT
public:
    explicit        GameScene(QObject* _parent = nullptr);

signals:

public slots:
    void            loop();

private:
    void            handlePlayerInput(
                        float   elapsedTime);
    void            resetKeyStatus();
    void            onUserCreate();
    void            renderGameObjects();
    void            createPixmap();
    void            drawString(
                        int     x,
                        int     y,
                        QString text);
    void            renderGameScene();
    KeyStatus*      m_keys[256];

    const int       FPS = _FPS;
    QTimer          m_timer;
    QElapsedTimer   m_elapsedTimer;
    float           m_deltaTime = 0.0f,
                    m_loopTime  = 0.0f;
    const float     m_loopSpeed = int(1000.0f/FPS);

    float           m_distance;         // Distance car has travelled around track
    float           m_curvature;        // Current track curvature, lerped between track sections
    float           m_trackCurvature;   // Accumulation of track curvature
    float           m_trackDistance;    // Total distance of track
    float           m_carPos;           // Current car position
    float           m_playerCurvature;  // Accumulation of player curvature
    float           m_speed;            // Current player speed

    QVector<QPair<float, float> >
                    m_vecTrack;         // Track sections, sharpness of bend, length of section
    QList<float>    m_listLapTimes;
    float           m_currentLapTime;
    int             m_carDirection;
    QImage          m_image;
    QPixmap         m_leftCarPixmap,
                    m_rightCarPixmap,
                    m_upCarPixmap;

protected:
    virtual void    keyPressEvent(
                        QKeyEvent *event) override;
    virtual void    keyReleaseEvent(
                        QKeyEvent *event) override;
};

class               GameThread :
                        public QThread
{
    Q_OBJECT
public:
    explicit        GameThread(
                    GameScene*  _m_gamescene,
                    QObject*    _parent = nullptr);
    GameScene*      getGameScene(void);

protected:
    void            run(void) override;

private:
    GameScene*      m_gameScene;
};

#endif // GAMESCENE_H
