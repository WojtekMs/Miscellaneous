#include <cstdlib>

int main() {
    //completely not cross-platform!
    system("ls");
    system("touch file.txt");
    system("echo 'hello!' > file.txt");
    system("cat file.txt");
    system("sudo ls -l");
}
