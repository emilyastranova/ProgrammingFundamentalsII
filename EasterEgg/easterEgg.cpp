#include <iostream>
#include <bits/stdc++.h> 

using namespace std;
void easterEgg();
int main()
{
    easterEgg();
}

void easterEgg()
{    
    for(int i = 0; i < 8; i++)
    {
        string lines[] = 
        {
            "\"\"aaaaaaa\"aaaaa\"\"\"aaaa\"\"a\"\"\"a\"",
            "\"~aa\"\"\"aa~\"\"aa\"^\"1\"aa\"^~\"^\"~\"~",
            "\"\"\"\"~\"~\"\"~\"~aa+\"~\"~\"\"~\"~\"\"^~\"~",
            "\"\"\"\"~\"~\"\"~\"\"a\"\"1~\"~\"\"~\"~\"0\"b\"~",
            "\"\"\"\"~\"~\"\"~\"~\"^\"^~\"~aa~\"~\"~^\"\"~",
            "\"\"\"\"~a~\"\"~a~\"\"^a^^aaaa1~a~\"^a~",
            "",
            "\"\"\"\"\"K\"hkijv\"hqt\"vjg\"wugtu"
        };
    
        int n = lines[i].length(); 
        char char_array[n + 1]; 
        strcpy(char_array, lines[i].c_str()); 

        for(int i = 0; (i < 100 && char_array[i] != '\0'); i++)
                char_array[i] = char_array[i] - 2;
        cout << char_array << endl;
    }
}