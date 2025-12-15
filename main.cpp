#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <RtMidi.h>
#include <Mixers/NanoKontrol2/nanokontrol2.h>


#include <iostream>
#include <memory>


int main(int argc, char *argv[])
{
    std::cout << "BEEP" << std::endl;

    std::unique_ptr<NanoKontrol2> mixer = std::make_unique<NanoKontrol2>(0,1);


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MidiMixer", "Main");

    return app.exec();
}
