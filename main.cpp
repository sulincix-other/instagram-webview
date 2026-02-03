#include <QApplication>
#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <QUrl>
#include <QDebug>
#include <QProcess>
#include <QStandardPaths>

class CustomWebEnginePage : public QWebEnginePage {
public:
    CustomWebEnginePage(QWebEngineProfile *profile, QObject *parent = nullptr)
        : QWebEnginePage(profile, parent) {}

protected:
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame) override {
        // Allow navigation for Instagram links
        if (url.host().toStdString().find("instagram.com")  != std::string::npos) {
            return true;
        } else if (url.host().toStdString().find("facebook.com")  != std::string::npos) {
            // Block facebook related links
            return false;
        } else {
            // Open other links with xdg-open
            QProcess::startDetached("xdg-open", QStringList() << url.toString());
            return false;
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Instagram");
    auto profile = new QWebEngineProfile("Instagram", &window);
    auto view = new QWebEngineView(&window);
    view->setPage(new CustomWebEnginePage(profile, view));

    // Load initial URL
    view->setUrl(QUrl("https://instagram.com"));

    window.setCentralWidget(view);
    window.resize(800, 600);
    window.show();

    return app.exec();
}
