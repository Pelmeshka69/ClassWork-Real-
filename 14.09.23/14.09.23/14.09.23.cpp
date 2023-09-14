#include <iostream>
#include <string>

using namespace std;

class Image {
private:
    unsigned short int width;
    unsigned short int height;
    string name;
    string extension;
    unsigned short int imageWeightInByte;

public:
    string format;
    string comment;
    string tags[100];
    unsigned short int rating;

    Image(unsigned short int inputWidth = 1000, unsigned short int inputHeight = 1000) {
        width = inputWidth;
        height = inputHeight;
        format = "";
        comment = "";
        extension = "";
        name = "";
        rating = 0;
        imageWeightInByte = width * height * 3;
    }

    // GET
    unsigned short int getWidth() { return width; }
    unsigned short int getImageWeightInByte() { return imageWeightInByte; }
    string getName() { return name; }
    string getExtension() { return extension; }

    // SET
    void setWidth(unsigned short int inputWidth) {
        if (inputWidth > 500 && inputWidth < 10000) {
            width = inputWidth;
        }
    }

    void setName(string name) {
        string newName = "";
        for (int i = 0; i < name.size(); i++) {
            if (!isdigit(name[i])) {
                newName += name[i];
            }
        }
        this->name = newName;
    }

    void setExtension(string extension) {
        if (extension == ".png" || extension == ".jpg" || extension == ".tiff") {
            this->extension = extension;
        }
        else {
            this->extension = ".png";
        }
    }
};

int main() {
    Image first{ 640, 1280 };
    first.setName("Image54");
    first.setExtension(".tiff");
    cout << first.getName() + first.getExtension();
}
