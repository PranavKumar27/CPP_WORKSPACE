#include <iostream>
#include <winsock.h>

#define PORT 9906
using namespace std;

int main()
{
    cout << "Socket Prog Creating Server Here" << endl;
    int nRet = 0;
    /// Initialize the WSA Variables
    WSADATA ws;
    if(WSAStartup(MAKEWORD(2,2),&ws)<0)
    {
     cout << " WSA Failed " << endl;
    }
    else
    {
        cout << "WSA Worked Fine" << endl;
    }

    /// Step 1: Initialize the socket
    int nsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    // We can also have as below
    // int nsocket = socket(AF_INET,SOCK_STREAM,0);
    // Here passing 0 means use underlying Protocol

    if(nsocket<0)
    {
        cout << "Failed to open Socket" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Socket Opened successfully"  << nsocket << endl;
    }


    /// Step 2: Initialize the environment for sock_addr structure
    sockaddr_in srv;
    srv.sin_family = AF_INET;
    srv.sin_port = htons(9909);
    srv.sin_addr.s_addr = INADDR_ANY; // Local Address of machine
    //srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(srv.sin_zero),0,8);

    int nOptVal = 0;
    int nOptSize = sizeof(nOptVal);
    nRet = setsockopt(nsocket,SOL_SOCKET,SO_REUSEADDR,(const char*)&nOptVal,nOptSize);
    if(!nRet)
    {
        cout << "Set Sockopt is successful" << endl;
    }
    else
    {
        cout << "setsockOpt Failed" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    /// Step 3: Binding the socket to local port
    nRet = bind(nsocket,(sockaddr*)&srv,sizeof(sockaddr));

    if(nRet<0)
    {
        cout << "Binding Failed" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Binding Success" << endl;
    }

    /// Step 4: Listen the Request and define Request Queue Size
    nRet = listen(nsocket,5);

    if(nRet<0)
    {
        cout << "Listener Failed" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Listener Success" << endl;
    }

    /// Step 5: Keep waiting for new Request and proceed as per  the request

    fd_set fr,fw,fe;
    // fr file read
    // fw  file write
    // fe file exception, errors throws in network due to any failure
    //These will be file descriptors on which we will write to the network, read over the nextwork
    // AT max we can have 64 socket descriptors. Like there are 64 fr, 64, fw and 64 fe

    int nmaxFd = nsocket;
    struct timeval tv; // Specify timeout
    tv.tv_sec = 1;
    tv.tv_usec=0;



    while(1)
    {

        // Set as Zero
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);

        // Set the socket
        FD_SET(nsocket,&fr);
        FD_SET(nsocket,&fe);

        cout << "Before select call fr.count=" << fr.fd_count << endl;

        // select call un-sets all the file decriptor
        nRet = select(nmaxFd+1,&fr,&fw,&fe,&tv);


        if(nRet>0)  // or if(I
        {
            // When some one connects or communicates with Message
            // over a dedicated connection
            cout << "Data on Port Processing ~ ~  ~ ~ ~" << endl;
            if(FD_ISSET(nsocket,&fe))
            {
                cout << "There is an exception Get away " << endl;
            }
            else if(FD_ISSET(nsocket,&fr))
            {
                cout << "Read to read Something new came up now" << endl;
            }
            else if(FD_ISSET(nsocket,&fw))
            {
                cout << "Read to write " << endl;
            }
            break;
        }
        else if(nRet == 0)
        {
            // No connection or any communication which was made
            // No-one of the sockets descriptors are ready
            cout << "Nothing on the Port" << PORT << endl;
        }
        else
        {
            cout << "App failed" << endl;
            // It failed and application has some error
            WSACleanup();
            exit(EXIT_FAILURE);
        }
        Sleep(2000);
    }
    cout << "After select call fr.count=" << fr.fd_count << endl;
    return 0;
}
