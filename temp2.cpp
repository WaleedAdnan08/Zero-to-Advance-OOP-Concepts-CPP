/*
Write a program that performs following string manipulations: You cannot change
prototype of any function.
1. Write a function that takes two strings i.e., str1 and str2 then appends str1 at the end of str2.
void StringConcatenate (char *str1, char *str2) ;
Note: Do not use any extra string inside the function.
2. Write a function that takes a string and if it finds more than one occurrences of a character in the
string, it removes the extra occurrences.
Void CompressString(char*);
For example:
String: “abadca” String after compression: “abdc”
String: “aaaaaaabbaad” String after compression: “abd”
Note: Do not use any extra string inside the function.
3. Write a function that takes a sentence and returns its inverse.
Char* ReverseSentence(char*)
String: “I am Pakistani”
After calling Reverse Sentence
String: “Pakistani am I” (Do not change the original string)
4. Write a function that takes a 2d-array of singular words and convert each singular word of array
to a plural word.
void pluralWords(char **s, int wordCount);
a. Append ‘es’ in following cases
1. If a word ends with letter ‘h’ and second last letters are ‘c’ or ‘s’
2. If last letter is ‘x’ or ‘is’
Tax – Taxes
Analysis – Analyses
Ellipsis – Ellipses
3. If last letter is ‘s’ or ‘z’ and second last letter is not vowel a
4. If the word ends in ‘ato’
Potato – Potatoes
Tomato – Tomatoes
b. If last letter is ‘z’ and second last letter is vowel ‘a’ or ‘e’ then append ‘zes’
Quiz – Quizzes
c. If last letter is ‘s’ and second last letter is vowel ‘a’ or ‘e’ the append ‘ses’
Gas – Gasses
d. If the noun ends with ‘ff’ then append ‘s’
Staff – Staffs
Stuff – Staffs
Lay-off – Lay-offs
Object Oriented Programming (CS-217) Spring 2021 Section A, B
National University of Computer and Emerging Sciences, Lahore
e. If the noun ends with ‘f’ or ‘fe’, the f is changed to ‘ve’ before adding the ‘s’ to form the
plural version.
Wife – Wives,
Wolf – Wolves
f. If the singular noun ends in ‘on’, then ‘‘on’’ is changed to ‘a’.
Phenomenon – Phenomena
Criterion – Criteria
1. If the singular noun ends in ‘us’, then ‘us’ is changed to ‘i’.
Cactus – Cacti
Focus – Foci
g. If last letter is ‘y’ and second last letter is vowel then append ‘s’ otherwise ‘ies’
City – Cities
Puppy – Puppies
Ray – Rays
Roy – Boys
h. For all other options append ‘s’
 Input array After function call Array should contain
Student
Party
Quiz
Wolf
Students
Parties
Quizzes
Wolves
Carefully reallocate memory to store plural words.
- You cannot change the function prototypes given in the questions.
- You cannot use break or goto statements. Breaks are allowed in switch cases.
- Built-in string functions are not allowed.
- Do not use new/extra strings wherever mentioned in the questions.

*/

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;
void Calcualting_completeSentence(char *&str, const char currentLetter, int &totalLetters)
{
    char *temp = new char[totalLetters + 1];
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp[i] = str[i];
    }
    temp[totalLetters - 1] = currentLetter;
    temp[totalLetters] = '\0';
    delete[] str;
    str = temp;
    totalLetters++;
}
void spaces() { cout << "\n\n\n"; }
void paragraph()
{
    spaces();
    cout << "\t\t WELCOME TO THE SALIK TYPING SPEED TEST\n";
    spaces();
    cout << "Being human makes us susceptible to the onset of feelings. The role of these emotions varies. Some of them are useful while others may be harmful. The use of social media for self-expression has reached a point that it makes us feel we can say anything. This begins when we see people expressing anything and everything that come to mind. When we see everyone else voicing their likes and dislikes, their irritations and desires we tend to imitate what they do. And because many engage in this, we think that it is normal and healthy. However, when we get used to unbridled self-expression, we come to believe that all feelings are valid. We become convinced that in real life, we should also act on our emotions and our impulses. Using social media this way erodes our ability to regulate our actions and reactions. To illustrate, when something small irritates us we think that it's okay to feel this way. But isn't it better to foster one's patience and resilience instead of immediately complaining? Or when we develop an attraction to someone despite that person being in a relationship, and because social media has conditioned us that all feelings can be expressed, we tend to think that acting on this attraction is okay. Not all feelings deserve expression. We find ourselves creating our own problems when we let our present emotions control our actions.\n";
    spaces();
}
int UI(char &currentLetter)
{
    paragraph();
    cout << "To start the Test press enter \'S-key\' \n";
    currentLetter = getch();
    currentLetter = tolower(currentLetter);
    while (currentLetter != 's')
    {
        cout << "Please press the valid key : \n";
        currentLetter = getch();
    }
    cout << "\t\t\t YOUR TEST STARTS, start typing \n\n\n";
    return time(0);
}
void timePassedAway(int startTime)
{
    int currentTime = time(0);
    int sec = currentTime - startTime;
    int min = 0, hour = 0;
    if (sec > 59)
    {
        min++;
        sec = 0;
    }
    if (min > 59)
    {
        hour++;
        min = 0;
        sec = 0;
    }

    cout << "Time passed : " << hour << " : " << min << " : " << sec << "\n";
}
void displayingSentences(char &currentLetter, char *&str, int &totalLetters, int startTime)
{
    while (currentLetter != 13)
    {
        currentLetter = getch();
        if ((currentLetter >= 32 && currentLetter <= 126) || currentLetter==13)
        {
            Calcualting_completeSentence(str, currentLetter, totalLetters);
            system("cls");
            int currentTime = time(0);
            paragraph();
            cout << "\n\nTotal Letters = " << totalLetters - 1 << "\n";
            timePassedAway(startTime);
            spaces();
            for (int i = 0; str[i] != '\0'; i++)
            {
                cout << str[i];
            }
            spaces();
            spaces();
            cout<<"To END : PRESS ENTER-KEY\n";
        }
        else
        {
            currentLetter = getch();
        }
    }
}

int main()
{
    int totalLetters = 1;
    char *str = new char[totalLetters]{'\0'};
    char currentLetter = 13;
    int startTime = UI(currentLetter);
    displayingSentences(currentLetter, str, totalLetters, startTime);

    delete[] str;
    str = nullptr;

    return 0;
}
