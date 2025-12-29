#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int nScreenWidth = 80;
int nScreenHeight = 30;

int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    case 0:
        return py * 4 + px;
    case 1:
        return 12 + py - (px * 4);
    case 2:
        return 15 - (py * 4) - px;
    case 3:
        return 3 - py + (px * 4);
    }
    return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{

    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
        {
            // Get index into piece
            int pi = Rotate(px, py, nRotation);

            // Get index into field
            int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

            if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
            {
                if (nPosY + py >= 0 && nPosY + py < nFieldHeight)

                {
                    if (tetromino[nTetromino][pi] == L'X' && pField[fi] != 0)
                        return false; // fail on first hit
                }
            }
        }
    return true;
}

int main()
{
    // Create assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");

    tetromino[3].append(L"....");
    tetromino[3].append(L"...X");
    tetromino[3].append(L"...X");
    tetromino[3].append(L"XXXX");

    tetromino[4].append(L"....");
    tetromino[4].append(L"....");
    tetromino[4].append(L"XXXX");
    tetromino[4].append(L"XXXX");

    tetromino[5].append(L"XXXX");
    tetromino[5].append(L"X...");
    tetromino[5].append(L"X...");
    tetromino[5].append(L"....");

    tetromino[6].append(L"....");
    tetromino[6].append(L"....");
    tetromino[6].append(L"....");
    tetromino[6].append(L"XXXX");

    pField = new unsigned char[nFieldWidth * nFieldHeight];

    for (int x = 0; x < nFieldWidth; x++)
        for (int y = 0; y < nFieldHeight; y++)
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;

    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    screen[nScreenWidth * nScreenHeight - 1] = L'\0';

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // 1. Shrink window first
    SMALL_RECT rectWindow = {0, 0, 1, 1};
    SetConsoleWindowInfo(hConsole, TRUE, &rectWindow);

    // 2. Set buffer size = screen size
    SetConsoleScreenBufferSize(
        hConsole,
        {(short)nScreenWidth, (short)nScreenHeight});

    // 3. Expand window to match buffer
    rectWindow = {
        0,
        0,
        (short)(nScreenWidth - 1),
        (short)(nScreenHeight - 1)};
    SetConsoleWindowInfo(hConsole, TRUE, &rectWindow);

    bool bGameOver = false;

    int nCurrentPiece = 0; // anong tetromino
    int nCurrentRotation = 0;
    int nCurrentX = nFieldWidth / 2 - 2;
    int nCurrentY = 0;

    while (!bGameOver)

    // game timing ===============================

    // input =====================================

    // game logic ================================

    // render ====================================
    {
        // CLEAR SCREEN
        for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
            screen[i] = L' ';

        // DRAW FIELD (Y then X)
        for (int y = 0; y < nFieldHeight; y++)
        {
            for (int x = 0; x < nFieldWidth; x++)
            {
                screen[(y + 2) * nScreenWidth + (x + 2)] =
                    L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
            }

            for (int px = 0; px < 4; px++)
            {
                for (int py = 0; py < 4; py++)
                {
                    if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
                    {
                        screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = L'A' + nCurrentPiece;
                    }
                }
            }
        }

        WriteConsoleOutputCharacterW(hConsole,
                                     screen,
                                     nScreenWidth * nScreenHeight,
                                     {0, 0},
                                     &dwBytesWritten

        );

        Sleep(50);
    }

    return 0;
}
