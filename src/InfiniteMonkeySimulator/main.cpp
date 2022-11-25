#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <bits/stdc++.h>

using namespace std;

string formNum(long long int rawNum);
string strRep(string charIn, int amount);
void cc();

const string ver = "v2.0.0";

main()
{
    system(("title InfiniteMonkeySimulator " + ver).c_str());
    system("color 3");
    cout << "  ___       __ _      _ _       __  __          _            ___ _           _      _           \n"
            " |_ _|_ _  / _(_)_ _ (_) |_ ___|  \\/  |___ _ _ | |_____ _  _/ __(_)_ __ _  _| |__ _| |_ ___ _ _ \n"
            "  | || ' \\|  _| | ' \\| |  _/ -_) |\\/| / _ \\ ' \\| / / -_) || \\__ \\ | '  \\ || | / _` |  _/ _ \\ '_|\n"
            " |___|_||_|_| |_|_||_|_|\\__\\___|_|  |_\\___/_||_|_\\_\\___|\\_, |___/_|_|_|_\\_,_|_\\__,_|\\__\\___/_|  \n"
            "                                                        |__/                                    ";
    cout << ver + "\n" + strRep(" ", 96) + "by o7q\n";
    
    while (true)
    {
        cout << "\n+" + strRep("=", 45) + "+\n";

        cout << "\nSEARCH PHRASE (no spaces):\n-> ";
        string input; cin >> input; cc();

        // alphabet configuration

        // alphabet input
        cout << "\nCUSTOM ALPHABET (no spaces):\n"
                "lower    (lowercase letters only)\n"
                "upper    (uppercase letters only)\n"
                "both     (lowercase and uppercase letters only)\n"
                "num      (numbers only)\n"
                "numlower (numbers and lowercase letters only)\n"
                "numupper (numbers and uppercase letters only)\n"
                "numboth  (numbers, lowercase, and uppercase letters only)\n"
                "custom   (input your own)\n-> ";
        string alphabet_input; cin >> alphabet_input; cc();
        // declare alphabet information
        string alphabet;
        string alphabet_types[] =
            {
                "lower",
                "upper",
                "both",
                "num",
                "numlower",
                "numupper",
                "numboth"
            };
        string alphabet_dictionary[] =
            {
                "abcdefghijklmnopqrstuvwxyz",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "0123456789",
                "0123456789abcdefghijklmnopqrstuvwxyz",
                "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
            };
        // process alphabet
        for (int i = 0; i <= 7; i++) if (alphabet_input == alphabet_types[i]) alphabet = alphabet_dictionary[i];
        // handle custom alphabet
        int alphabet_type_index = 0;
        for (int i = 0; i < 7; i++) if (alphabet_input != alphabet_types[i]) alphabet_type_index++;
        if (alphabet_type_index == sizeof(alphabet_types) / sizeof(alphabet_types[0])) alphabet = alphabet_input;

        cout << "\nMAXIMUM ATTEMPTS (! for infinite):\n-> ";
        string attempts_str; cin >> attempts_str; cc();
        long long int attempts = attempts_str == "!" ? 9223372036854775807 : stoi(attempts_str);

        // compute attempts
        const int input_length = input.length();
        const int alphabet_length = alphabet.length();
        const long long int attemptsApprox = pow(alphabet_length, input_length) + 1;
        const string attemptsText = attempts == 1 ? "ATTEMPT" : "ATTEMPTS";

        // create vars
        int attempt = 0;
        string finalStr;
        bool isRunning = true;
        // mersenne twister
        srand(time(NULL));
        mt19937 gen(rand());
        uniform_int_distribution<> dist(0, alphabet_length - 1);

        // split alphabet in chars
        string s(alphabet);
        vector<char> v(s.begin(), s.end());

        cout << "\nIT WILL TAKE APPROXIMATELY " + formNum(attemptsApprox) + " ATTEMPTS TO FINISH!\nDO YOU WANT TO DISPLAY THE OUTPUT? (slow) (y = yes | anything else = no)\n-> ";
        char displayOutput; cin >> displayOutput; cc();
        cout << endl;

        cout << "READY! PRESS ANY KEY TO START...\n";
        system("pause");
        cout << endl;

        for (int i = 0; i < attempts; i++)
        {
            string str;
            for (int n = 0; n < input_length; n++) { str += v[dist(gen)]; }
            attempt++;

            if (displayOutput == 'y') printf((str + " | " + formNum(attempt) + "\n").c_str());

            if (str == input)
            {
                isRunning = false;
                cout << "\nFOUND \"" + input + "\" IN " + formNum(attempt) + " " + attemptsText + "! (max: " + formNum(attempts) + ")\nTRY ANOTHER? (y = yes | anything else = no)\n-> ";
                char r; cin >> r; cc();
                if (r == 'y') break; else return 0;
            }
            finalStr = str;
        }

        if (finalStr != input && isRunning)
        {
            cout << "\nCOULD NOT FIND \"" + input + "\" IN " + formNum(attempts) + " " + attemptsText +"!\nRETRY? (y = yes | anything else = no)\n-> ";
            char r; cin >> r; cc();
            if (r != 'y') return 0;
        }
    }
}

string formNum(long long int rawNum)
{
    string numForm;
    string num = to_string(rawNum);
  
    int count = 0;
  
    for (int i = num.size() - 1; i >= 0; i--)
    {
        count++;
        numForm.push_back(num[i]);
  
        if (count == 3)
        {
            numForm.push_back(',');
            count = 0;
        }
    }
  
    reverse(numForm.begin(), numForm.end());
  
    if (numForm.size() % 4 == 0) numForm.erase(numForm.begin());
  
    return numForm;
}

// string repeater function
string strRep(string charIn, int amount)
{
    string output;
    for (int i = 0; i < amount; i++) output += charIn;
    return output;
}

// cin clear function
void cc()
{
    cin.clear();
    cin.sync();
}