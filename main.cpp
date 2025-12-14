#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <RtMidi.h>
#include <iostream>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MidiMixer", "Main");


    std::cout << "test" << std::endl;

    return app.exec();
}
