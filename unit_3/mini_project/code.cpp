#include <iostream>
#include <vector>
using namespace std;

// Base class
class Media
{
protected:
    string title;

public:
    Media(string t)
    {
        title = t;
    }

    // Virtual functions
    virtual void play()
    {
        cout << "Playing media: " << title << endl;
    }

    virtual void pause()
    {
        cout << "Pausing media: " << title << endl;
    }

    virtual void stop()
    {
        cout << "Stopping media: " << title << endl;
    }

    virtual void showDetails()
    {
        cout << "Title: " << title << endl;
    }

    // Virtual destructor
    virtual ~Media() {}
};

// Derived class Audio
class Audio : public Media
{
private:
    string artist;

public:
    Audio(string t, string a) : Media(t)
    {
        artist = a;
    }

    void play() override
    {
        cout << "Playing audio: " << title << endl;
    }

    void pause() override
    {
        cout << "Pausing audio: " << title << endl;
    }

    void stop() override
    {
        cout << "Stopping audio: " << title << endl;
    }

    void showDetails() override
    {
        cout << "Audio: " << title << " | Artist: " << artist << endl;
    }
};

// Derived class Video
class Video : public Media
{
private:
    string resolution;

public:
    Video(string t, string r) : Media(t)
    {
        resolution = r;
    }

    void play() override
    {
        cout << "Playing video: " << title << endl;
    }

    void pause() override
    {
        cout << "Pausing video: " << title << endl;
    }

    void stop() override
    {
        cout << "Stopping video: " << title << endl;
    }

    void showDetails() override
    {
        cout << "Video: " << title << " | Resolution: "
             << resolution << endl;
    }
};

// Derived class Image
class Image : public Media
{
private:
    string format;

public:
    Image(string t, string f) : Media(t)
    {
        format = f;
    }

    void play() override
    {
        cout << "Displaying image: " << title << endl;
    }

    void pause() override
    {
        cout << "Pausing image display: " << title << endl;
    }

    void stop() override
    {
        cout << "Closing image: " << title << endl;
    }

    void showDetails() override
    {
        cout << "Image: " << title << " | Format: " << format << endl;
    }
};

int main()
{
    // Collection of base-class pointers
    vector<Media*> mediaList;

    mediaList.push_back(new Audio("Believer", "Imagine Dragons"));
    mediaList.push_back(new Video("Avengers Trailer", "1080p"));
    mediaList.push_back(new Image("Nature Photo", "JPG"));

    cout << "===== MEDIA PLAYER =====\n\n";

    // Polymorphic behavior
    for (Media* media : mediaList)
    {
        media->showDetails();
        media->play();
        media->pause();
        media->stop();

        cout << "------------------------\n";
    }

    // Free dynamically allocated memory
    for (Media* media : mediaList)
    {
        delete media;
    }

    return 0;
}
