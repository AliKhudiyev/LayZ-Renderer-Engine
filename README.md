# LayZ Renderer Engine

![Image](LayZ.png)

**LayZ** is a simple cross-platform renderer engine written in C/C++ using OpenGL specification. 


## How to launch

<table>
<thead>
<tr>
    <th colspan=2 style="text-align:center">Requirements</th>
</tr>
</thead>

<tbody>
<tr>
    <td>OS</td>
    <td>Linux, MacOS, Windows</td>
</tr>
<tr>
    <td>OpenGL version</td>
    <td>3.3+</td>
</tr>
<tr>
    <td>RAM</td>
    <td>2 GB</td>
</tr>
<tr>
    <td>Disk space</td>
    <td>3 GB</td>
</tr>
</tbody>
</table>


## How to use

There is a wiki(not completely prepared yet) that you can always open and check the detailed tutorials.

```
#include <layz.h>

using namespace std;

int main() {

    lyz::init();

    lyz::Window win = lyz::Window("Example Window", 640, 480);
    auto renderer2D = lyz::Renderer::getRenderer2D();
    
    while(win->isRunnning()) {
        renderer2D.store(?);
        renderer2D.draw();
        win->onUpdate();
    }
    
    lyz::deinit();

    return 0;
}

```