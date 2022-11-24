#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

void cc();

const string ver = "v1.0.1";

main()
{
    system("color 3");
    cout << "InfiniteMonkeyCalculator " + ver + "\nby o7q\n";
    while (true)
    {
        cout << "\n+========================================+\n";

        cout << "\nSEARCH PHRASE (lowercase only, no spaces):\n- ";
        string input; cin >> input; cc();

        cout << "\nMAXIMUM ATTEMPTS (! for infinite):\n- ";
        string attempts_str; cin >> attempts_str; cc();
        long long int attempts;
        attempts = attempts_str == "!" ? 9223372036854775807 : stoi(attempts_str);

        cout << "\nDISPLAY OUTPUT? (slow) (y = yes | anything else = no)\n- ";
        char displayOutput; cin >> displayOutput; cc();
        cout << endl;

        const int input_length = input.length();
        string attemptsText = attempts == 1 ? "ATTEMPT" : "ATTEMPTS";

        int count = 0;
        string finalStr;
        bool isRunning = true;

        srand(time(NULL));
        mt19937 gen(rand());
        uniform_int_distribution<> dist(0, 25);

        for (int i = 0; i < attempts; i++)
        {
            string str;
            for (int n = 0; n < input_length; n++) { char c = 'a' + dist(gen); str += c; }
            count++;

            if (displayOutput == 'y') printf((str + " | " + to_string(count) + "\n").c_str());

            if (str == input)
            {
                isRunning = false;
                cout << "\nFOUND \"" + input + "\" IN " + to_string(count) + " " + attemptsText + "! (max: " + to_string(attempts) + ")\nTRY ANOTHER? (y = yes | anything else = no)\n- ";
                char r; cin >> r; cc();
                if (r == 'y') break; else return 0;
            }
            finalStr = str;
        }

        if (finalStr != input && isRunning)
        {
            cout << "\nCOULD NOT FIND \"" + input + "\" IN " + to_string(attempts) + " " + attemptsText +"!\nRETRY? (y = yes | anything else = no)\n- ";
            char r; cin >> r; cc();
            if (r != 'y') return 0;
        }
    }
}

// cin clear function
void cc()
{
    cin.clear();
    cin.sync();
}