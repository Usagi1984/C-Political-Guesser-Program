#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <typeinfo>
#include <algorithm>
#include <limits>

using namespace std;

//Declares blank answer array for keeping track of answers
int answerArr [4][20] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

//Declare leaning score values
int authLeftScore = 0;

int authRightScore = 0;

int libLeftScore = 0;

int libRightScore = 0;

//Declare leaning arrays
int authLeftArr[4][20];

int authRightArr[4][20];

int libLeftArr[4][20];

int libRightArr[4][20];

//Declare total variables
int authLeftArrTotal = 0;

int authRightArrTotal = 0;

int libLeftArrTotal = 0;

int libRightArrTotal = 0;

//declare question variables
string q1 = "I’d always support my country, whether it was right or wrong.";
string q2 = "The enemy of my enemy is my friend.";
string q3 = "There is now a worrying fusion of information and entertainment.";
string q4 = "The freer the market, the freer the people.";
string q5 = "The rich are too highly taxed.";
string q6 = "Governments should penalise businesses that mislead the public.";
string q7 = "All authority should be questioned.";
string q8 = "Schools should not make classroom attendance compulsory.";
string q9 = "Abstract art that doesn’t represent anything shouldn’t be considered art at all.";
string q10 = "It is a waste of time to try to rehabilitate some criminals.";
string q11 = "The businessperson and the manufacturer are more important than the writer and the artist.";
string q12 = "Astrology accurately explains many things.";
string q13 = "You cannot be moral without being religious.";
string q14 = "Some people are naturally unlucky.";
string q15 = "No one chooses their country of birth, so it’s foolish to be proud of it.";
string q16 = "Military action that defies international law is sometimes justified.";
string q17 = "People are ultimately divided more by class than by nationality.";
string q18 = "“from each according to his ability, to each according to his need” is a fundamentally good idea.";
string q19 = "It’s a sad reflection on our society that something as basic as drinking water is now a bottled, branded consumer product.";
string q20 = "Land shouldn’t be a commodity to be bought and sold.";

string q21 = "What is your political leaning?\n(1 for \"AuthRight\", 2 for \"AuthLeft\", 3 for \"LibRight\", 4 for \"LibLeft\"): ";

//Wirte data function, updates data files
int WriteData(string filename, int name[4][20]){
    ofstream outfile(filename);
        if (outfile.is_open()) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                outfile << name[i][j] << " ";
            }
            outfile << "\n";
        }
        outfile.close();
    }
    cout << "Associated data file updated";
    return 0;
}

//Leaning function
int leaning;
int LeaningQuestion(){
    do{
        cout << q21 << endl;
        cin >> leaning;
        if(leaning < 1 || leaning > 4){
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }while(true);

    switch (leaning)
    {
    case 1:
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                authRightArr[i][j] += answerArr[i][j];
            }
        }

        WriteData("AuthRight.txt", authRightArr);
        exit(0);
        break;

    case 2:
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                authLeftArr[i][j] += answerArr[i][j];
            }
        }

        WriteData("AuthLeft.txt", authLeftArr);
        exit(0);
        break;

    case 3:
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                libRightArr[i][j] += answerArr[i][j];
            }
        }

        WriteData("LibRight.txt", libRightArr);
        exit(0);
        break;

    case 4:
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                libLeftArr[i][j] += answerArr[i][j];
            }
        }

        WriteData("LibLeft.txt", libLeftArr);
        exit(0);
        break;
    
    default:
        break;
    }

    return leaning;
}

int Prediction(int questionNumber){

    //Convert int values to doubles for calculation
    double authLeftScoreDouble = authLeftScore;
    double authRightScoreDouble = authRightScore;
    double libLeftScoreDouble = libLeftScore;
    double libRightScoreDouble = libRightScore;

    double authLeftArrTotalDouble = authLeftArrTotal;
    double authRightArrTotalDouble = authRightArrTotal;
    double libLeftArrTotalDouble = libLeftArrTotal;
    double libRightArrTotalDouble = libRightArrTotal;

        if(authLeftScoreDouble >= authLeftArrTotalDouble / 4 * 0.75){
            cout << "***Prediction: You are Authoritarian Left." << endl;
            LeaningQuestion();
        }else if(authRightScoreDouble >= authRightArrTotalDouble / 4 * 0.75){
            cout << "***Prediction: You are Authoritarian Right." << endl;
            LeaningQuestion();
        }else if(libLeftScoreDouble >= libLeftArrTotalDouble / 4 * 0.75){
            cout << "***Prediction: You are Libertarian Left." << endl;
            LeaningQuestion();
        }else if(libRightScoreDouble >= libRightArrTotalDouble / 4 * 0.75){
            cout << "***Prediction: You are Libertarian Right." << endl;
            LeaningQuestion();
        }else if(questionNumber == 20){
            int highest = max({authLeftScoreDouble , authRightScoreDouble, libLeftScoreDouble , libRightScoreDouble});
            if(highest == authLeftScoreDouble){
                cout << "***Prediction: You are Authoritarian Left." << endl;
                LeaningQuestion();
            }else if(highest == authRightScoreDouble){
                cout << "***Prediction: You are Authoritarian Right." << endl;
                LeaningQuestion();
            }else if(highest == libLeftScoreDouble){
                cout << "***Prediction: You are Libertarian Left." << endl;
                LeaningQuestion();
            }else if(highest == libRightScoreDouble){
                cout << "***Prediction: You are Libertarian Right." << endl;
                LeaningQuestion();
            }

        }

    return 0;
}

//Scoring and predicting function
int Evaluate(int questionNumber){
    //add answer score to current points for each party
    //take added values of each data file and compare with current points

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 20; j++) {
                if(answerArr[i][j] == 1 && j == questionNumber){
                    authLeftScore += authLeftArr[i][j];
                    authRightScore += authRightArr[i][j];
                    libLeftScore += libLeftArr[i][j];
                    libRightScore += libRightArr[i][j];
                }
            }
        }

    return authLeftScore, authRightScore, libLeftScore, libRightScore;
}

//Asking questions function
int Question(string question, int questionNumber){
    
    int answer;
    do{
        cout << question << endl;
        cout << "\"1\" - Strongly Disagree, \"2\" - Disagree, \"3\" - Agree, \"4\" - Strongly Agree" << endl;
        cin >> answer;
        if(answer < 1 || answer > 4){
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            switch (answer)
            {
            case 1:
                answerArr [0][questionNumber-1] += 1;
                Evaluate(questionNumber-1);
                return 0;
            case 2:
                answerArr [1][questionNumber-1] += 1;
                Evaluate(questionNumber-1);
                return 0;
            case 3:
                answerArr [2][questionNumber-1] += 1;
                Evaluate(questionNumber-1);
                return 0;
            case 4:
                answerArr [3][questionNumber-1] += 1;
                Evaluate(questionNumber-1);
                return 0;
            default:
                break;
            }
        }
    }while(true);

    return 0;
}

int Import(string filename, int name[4][20]){
    //Import data files into a 2d array variable

    ifstream infile(filename);

    if (infile.is_open()) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                infile >> name[i][j];
            }
        }

        infile.close();
    }

    return name[4][20];
}

int Total(int array[4][20]){
    //Add up all numbers in 2d array and export to a variable

    int total;
    int finaltotal;

    for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 20; ++j) {
                total += array[i][j];
            }
        }

    finaltotal = total;
    total = 0;

    return finaltotal;
}

int Output(){
        cout << "leaning " << leaning << endl << endl;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << answerArr[i][j] << ",";
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << authLeftArr[i][j] << ",";
            }
            cout << endl;
        }

        cout << endl;
        cout << authLeftArrTotal << endl;

        cout << "authLeftScore " << authLeftScore << endl;

        cout << "authRightScore " << authRightScore << endl;

        cout << "libLeftScore " << libLeftScore << endl;

        cout << "libRightScore " << libRightScore << endl;

        return 0;
}

int main () {

        //Import data files into leaning arrays
        Import("AuthLeft.txt", authLeftArr);

        Import("AuthRight.txt", authRightArr);

        Import("LibLeft.txt", libLeftArr);

        Import("LibRight.txt", libRightArr);



        //Create total values of data files
        authLeftArrTotal = Total(authLeftArr);

        authRightArrTotal = Total(authRightArr);

        libLeftArrTotal = Total(libLeftArr);

        libRightArrTotal = Total(libRightArr);



        //ask questions
        int a1 = Question(q1,1);
        Prediction(1);
        int a2 = Question(q2,2);
        Prediction(2);
        int a3 = Question(q3,3);
        Prediction(3);
        int a4 = Question(q4,4);
        Prediction(4);
        int a5 = Question(q5,5);
        Prediction(5);
        int a6 = Question(q6,6);
        Prediction(6);
        int a7 = Question(q7,7);
        Prediction(7);
        int a8 = Question(q8,8);
        Prediction(8);
        int a9 = Question(q9,9);
        Prediction(9);
        int a10 = Question(q10,10);
        Prediction(10);
        int a11 = Question(q11,11);
        Prediction(11);
        int a12 = Question(q12,12);
        Prediction(12);
        int a13 = Question(q13,13);
        Prediction(13);
        int a14 = Question(q14,14);
        Prediction(14);
        int a15 = Question(q15,15);
        Prediction(15);
        int a16 = Question(q16,16);
        Prediction(16);
        int a17 = Question(q17,17);
        Prediction(17);
        int a18 = Question(q18,18);
        Prediction(18);
        int a19 = Question(q19,19);
        Prediction(19);
        int a20 = Question(q20,20);
        Prediction(20);

        //leaning question
        LeaningQuestion();

        //ouptut values
        Output();

  return 0;
}