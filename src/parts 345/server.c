#include "fcgi_stdio.h"

int main(void) {
    FCGX_Init();
    FCGX_Request request;
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) >= 0) {
        FCGX_FPrintF(request.out, "Content-type: text/html\n\n");
        FCGX_FPrintF(request.out, "Hello, World!\n\n");
        FCGX_Finish_r(&request);
    }
    return 0;
}
