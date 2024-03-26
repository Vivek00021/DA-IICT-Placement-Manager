#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------------>
//------------------------------------------------------------- NODE'S TYPE ---------------------------------------------------------------->
//------------------------------------------------------------------------------------------------------------------------------------------>

//--->Node Type for Round1,Round2,Round3,HR Round

class Node1
{
public:
    long long id;
    string name;
    int batch;
    string program;
    string email;
    long long contactNO;
    long long whatsappNO;
    string company;
    Node1 *next;

    Node1(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company)
    {
        this->id = id;
        this->name = name;
        this->batch = batch;
        this->program = program;
        this->email = email;
        this->contactNO = contactNO;
        this->whatsappNO = whatsappNO;
        this->company = company;
        next = NULL;
    }
};

//--->Node Type for Final Round

class Node2
{
public:
    long long id;
    string name;
    int batch;
    string program;
    string email;
    long long contactNO;
    long long whatsappNO;
    string company;
    float pakage;
    Node2 *next;

    Node2(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company, float pakage)
    {
        this->id = id;
        this->name = name;
        this->batch = batch;
        this->program = program;
        this->email = email;
        this->contactNO = contactNO;
        this->whatsappNO = whatsappNO;
        this->company = company;
        this->pakage = pakage;
        next = NULL;
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------>
//------------------------------------------------------------------------------------------------------------------------------------------>
//----------------------------------------------------------- Placement Management Class --------------------------------------------------->
//------------------------------------------------------------------------------------------------------------------------------------------>
//------------------------------------------------------------------------------------------------------------------------------------------>

class PlacementManager
{

private:
    //--------------- Variables for Creating List and to Manage Placement Statics  -------->

    // Head and Tail Pointers for Round 1

    Node1 *HeadR1;
    Node1 *TailR1;

    // Head and Tail Pointers for Round 2

    Node1 *HeadR2;
    Node1 *TailR2;

    // Head and Tail Pointers for Round 3

    Node1 *HeadR3;
    Node1 *TailR3;

    // Head and Tail Pointers for Round 4

    Node1 *HeadR4;
    Node1 *TailR4;

    // Head and Tail Pointers for Round 5

    Node2 *HeadFR;
    Node2 *TailFR;

    // Variables to keep Track on whole Placement Statics

    int NOofStudentR1;
    int NOofStudentR2;
    int NOofStudentR3;
    int NOofStudentR4;
    int NOofStudentFR;
    float TotalPakages;

    //------------------------------------------------------------------------------------------------------------------------------------------>
    //------------------------------------------------------------------------------------------------------------------------------------------>
    //-------------------------------------------------- Functions to Create list for Respective Round ----------------------------------------->
    //------------------------------------------------------------------------------------------------------------------------------------------>
    //------------------------------------------------------------------------------------------------------------------------------------------>

    //--------------------------------------------------------------------------------------------------------------------->
    //------------------------------------------------Function to add Node in Round1's list-------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void addToListR1(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company)
    {
        Node1 *NewNode = new Node1(id, name, batch, program, email, contactNO, whatsappNO, company);

        if (NewNode == NULL)
        {
            cerr << "\nUnable to allocate Memory For Creating Node for Round1\n";
            return;
        }
        else
        {
            if (HeadR1 == NULL)
            {
                HeadR1 = NewNode;
                TailR1 = NewNode;
                return;
            }
            if (NewNode->id <= HeadR1->id)
            {
                NewNode->next = HeadR1;
                HeadR1 = NewNode;
                return;
            }
            if (TailR1->id <= NewNode->id)
            {
                TailR1->next = NewNode;
                TailR1 = NewNode;
                return;
            }
            else
            {
                Node1 *Prev = NULL;
                Node1 *Current = HeadR1;
                while (!(NewNode->id <= Current->id) && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->next;
                }

                if (Current == NULL)
                {
                    cerr << "\nSomething went wrong while inserting node in Round1's List\n";
                    return;
                }
                else
                {
                    Prev->next = NewNode;
                    NewNode->next = Current;
                    return;
                }
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //------------------------------------------------Function to add Node in Round2's list-------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void addToListR2(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company)
    {
        Node1 *NewNode = new Node1(id, name, batch, program, email, contactNO, whatsappNO, company);

        if (NewNode == NULL)
        {
            cerr << "\nUnable to allocate Memory For Creating Node for Round2\n";
            return;
        }
        else
        {
            if (HeadR2 == NULL)
            {
                HeadR2 = NewNode;
                TailR2 = NewNode;
                return;
            }
            if (NewNode->id <= HeadR2->id)
            {
                NewNode->next = HeadR2;
                HeadR2 = NewNode;
                return;
            }
            if (TailR2->id <= NewNode->id)
            {
                TailR2->next = NewNode;
                TailR2 = NewNode;
                return;
            }
            else
            {
                Node1 *Prev = NULL;
                Node1 *Current = HeadR2;
                while (!(NewNode->id <= Current->id) && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->next;
                }

                if (Current == NULL)
                {
                    cerr << "\nSomething went wrong while inserting node in Round2's List\n";
                    return;
                }
                else
                {
                    Prev->next = NewNode;
                    NewNode->next = Current;
                    return;
                }
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //------------------------------------------------Function to add Node in Round3's list-------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void addToListR3(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company)
    {
        Node1 *NewNode = new Node1(id, name, batch, program, email, contactNO, whatsappNO, company);

        if (NewNode == NULL)
        {
            cerr << "\nUnable to allocate Memory For Creating Node for Round3\n";
            return;
        }
        else
        {
            if (HeadR3 == NULL)
            {
                HeadR3 = NewNode;
                TailR3 = NewNode;
                return;
            }
            if (NewNode->id <= HeadR3->id)
            {
                NewNode->next = HeadR3;
                HeadR3 = NewNode;
                return;
            }
            if (TailR3->id <= NewNode->id)
            {
                TailR3->next = NewNode;
                TailR3 = NewNode;
                return;
            }
            else
            {
                Node1 *Prev = NULL;
                Node1 *Current = HeadR3;
                while (!(NewNode->id <= Current->id) && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->next;
                }

                if (Current == NULL)
                {
                    cerr << "\nSomething went wrong while inserting node in Round3's List\n";
                    return;
                }
                else
                {
                    Prev->next = NewNode;
                    NewNode->next = Current;
                    return;
                }
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //------------------------------------------------Function to add Node in Round4's list-------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void addToListR4(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company)
    {
        Node1 *NewNode = new Node1(id, name, batch, program, email, contactNO, whatsappNO, company);

        if (NewNode == NULL)
        {
            cerr << "\nUnable to allocate Memory For Creating Node for Round4\n";
            return;
        }
        else
        {
            if (HeadR4 == NULL)
            {
                HeadR4 = NewNode;
                TailR4 = NewNode;
                return;
            }
            if (NewNode->id <= HeadR4->id)
            {
                NewNode->next = HeadR4;
                HeadR4 = NewNode;
                return;
            }
            if (TailR4->id <= NewNode->id)
            {
                TailR4->next = NewNode;
                TailR4 = NewNode;
                return;
            }
            else
            {
                Node1 *Prev = NULL;
                Node1 *Current = HeadR4;
                while (!(NewNode->id <= Current->id) && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->next;
                }

                if (Current == NULL)
                {
                    cerr << "\nSomething went wrong while inserting node in Round4's List\n";
                    return;
                }
                else
                {
                    Prev->next = NewNode;
                    NewNode->next = Current;
                    return;
                }
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //-------------------------------------------Function to add Node in Final Round's list-------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void addToListFR(long long id, string name, int batch, string program, string email, long long contactNO, long long whatsappNO, string company, float pakage)
    {
        Node2 *NewNode = new Node2(id, name, batch, program, email, contactNO, whatsappNO, company, pakage);

        if (NewNode == NULL)
        {
            cerr << "\nUnable to allocate Memory For Creating Node for Final Round\n";
            return;
        }
        else
        {
            if (HeadFR == NULL)
            {
                HeadFR = NewNode;
                TailFR = NewNode;
                return;
            }
            if (NewNode->id <= HeadFR->id)
            {
                NewNode->next = HeadFR;
                HeadFR = NewNode;
                return;
            }
            if (TailFR->id <= NewNode->id)
            {
                TailFR->next = NewNode;
                TailFR = NewNode;
                return;
            }
            else
            {
                Node2 *Prev = NULL;
                Node2 *Current = HeadFR;
                while (!(NewNode->id <= Current->id) && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->next;
                }

                if (Current == NULL)
                {
                    cerr << "\nSomething went wrong while inserting node in Final Round's List\n";
                    return;
                }
                else
                {
                    Prev->next = NewNode;
                    NewNode->next = Current;
                    return;
                }
            }
        }
    }

    //------------------------------------------------------------------------------------------------------------------------------------------>
    //------------------------------------------------------------------------------------------------------------------------------------------>
    //-------------------------------------------------- Functions to Read Files for Respective Round ------------------------------------------>
    //------------------------------------------------------------------------------------------------------------------------------------------>
    //------------------------------------------------------------------------------------------------------------------------------------------>

    //--------------------------------------------------------------------------------------------------------------------->
    //-------------------------------------------Function to Read Round 1's File------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void ReadFileForRound1(const string &filepath, const string &CompanyName)
    {

        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << "\nError in Opening Round1's File\nPlease Try again with valid File Path :) \n";
            return;
        }
        else
        {

            cout << "\nFatching Data from The Round1's File---->\n";

            string line;

            getline(file, line); // Skip the first line

            while (getline(file, line))
            {
                stringstream ss(line);

                //--->Extract data from each line

                // Variables to Extact Data

                string WordToSkip; // To Skip Unnecessary data

                string id_str, name, program, batch_str, email, conatctNO_str, whatsappNO_str;
                int batch;
                long long id, contactNO, whatsappNO;

                getline(ss, WordToSkip, ','); // Ignore the Sr No.
                getline(ss, id_str, ',');
                id = stoll(id_str);
                getline(ss, name, ',');
                getline(ss, program, ',');
                getline(ss, batch_str, ',');
                batch = stoi(batch_str);
                getline(ss, WordToSkip, ','); // Igonre Interview Date
                getline(ss, email, ',');
                getline(ss, conatctNO_str, ',');
                contactNO = stoll(conatctNO_str);
                getline(ss, whatsappNO_str, ',');
                whatsappNO = stoll(whatsappNO_str);

                // Insert the extracted data into the list

                addToListR1(id, name, batch, program, email, contactNO, whatsappNO, CompanyName);

                NOofStudentR1++; // Increment in Number of student who passed in Round 1
            }

            cout << "<----Successfully Data Fatched From the Round1's File \n";
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //-------------------------------------------Function to Read Round 2's File------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void ReadFileForRound2(const string &filepath, const string &CompanyName)
    {

        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << "\nError in Opening Round2's File\nPlease Try again with valid File Path :) \n";
            return;
        }
        else
        {

            cout << "\nFatching Data from The Round2's File---->\n";

            string line;

            getline(file, line); // Skip the first line

            while (getline(file, line))
            {
                stringstream ss(line);

                //--->Extract data from each line

                // Variables to Extact Data

                string WordToSkip; // To Skip Unnecessary data

                string id_str, name, program, batch_str, email, conatctNO_str, whatsappNO_str;
                int batch;
                long long id, contactNO, whatsappNO;

                getline(ss, WordToSkip, ','); // Ignore the Sr No.
                getline(ss, id_str, ',');
                id = stoll(id_str);
                getline(ss, name, ',');
                getline(ss, program, ',');
                getline(ss, batch_str, ',');
                batch = stoi(batch_str);
                getline(ss, WordToSkip, ','); // Igonre Interview Date
                getline(ss, email, ',');
                getline(ss, conatctNO_str, ',');
                contactNO = stoll(conatctNO_str);
                getline(ss, whatsappNO_str, ',');
                whatsappNO = stoll(whatsappNO_str);

                // Insert the extracted data into the list

                addToListR2(id, name, batch, program, email, contactNO, whatsappNO, CompanyName);
                NOofStudentR2++; // Increment in Number of student who passed in Round 2
            }

            cout << "<----Successfully Data Fatched From the Round2's File \n";
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //-------------------------------------------Function to Read Round 3's File------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void ReadFileForRound3(const string &filepath, const string &CompanyName)
    {

        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << "\nError in Opening Round3's File\nPlease Try again with valid File Path :) \n";
            return;
        }
        else
        {

            cout << "\nFatching Data from The Round3's File---->\n";

            string line;

            getline(file, line); // Skip the first line

            while (getline(file, line))
            {
                stringstream ss(line);

                //--->Extract data from each line

                // Variables to Extact Data

                string WordToSkip; // To Skip Unnecessary data

                string id_str, name, program, batch_str, email, conatctNO_str, whatsappNO_str;
                int batch;
                long long id, contactNO, whatsappNO;

                getline(ss, WordToSkip, ','); // Ignore the Sr No.
                getline(ss, id_str, ',');
                id = stoll(id_str);
                getline(ss, name, ',');
                getline(ss, program, ',');
                getline(ss, batch_str, ',');
                batch = stoi(batch_str);
                getline(ss, WordToSkip, ','); // Igonre Interview Date
                getline(ss, email, ',');
                getline(ss, conatctNO_str, ',');
                contactNO = stoll(conatctNO_str);
                getline(ss, whatsappNO_str, ',');
                whatsappNO = stoll(whatsappNO_str);

                // Insert the extracted data into the list

                addToListR3(id, name, batch, program, email, contactNO, whatsappNO, CompanyName);
                NOofStudentR3++; // Increment in Number of student who passed in Round 3
            }

            cout << "<----Successfully Data Fatched From the Round3's File \n";
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //-------------------------------------------Function to Read Round 4's File------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void ReadFileForRound4(const string &filepath, const string &CompanyName)
    {

        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << "\nError in Opening Round4's File\nPlease Try again with valid File Path :) \n";
            return;
        }
        else
        {

            cout << "\nFatching Data from The Round4's File---->\n";

            string line;

            getline(file, line); // Skip the first line

            while (getline(file, line))
            {
                stringstream ss(line);

                //--->Extract data from each line

                // Variables to Extact Data

                string WordToSkip; // To Skip Unnecessary data

                string id_str, name, program, batch_str, email, conatctNO_str, whatsappNO_str;
                int batch;
                long long id, contactNO, whatsappNO;

                getline(ss, WordToSkip, ','); // Ignore the Sr No.
                getline(ss, id_str, ',');
                id = stoll(id_str);
                getline(ss, name, ',');
                getline(ss, program, ',');
                getline(ss, batch_str, ',');
                batch = stoi(batch_str);
                getline(ss, WordToSkip, ','); // Igonre Interview Date
                getline(ss, email, ',');
                getline(ss, conatctNO_str, ',');
                contactNO = stoll(conatctNO_str);
                getline(ss, whatsappNO_str, ',');
                whatsappNO = stoll(whatsappNO_str);

                // Insert the extracted data into the list

                addToListR4(id, name, batch, program, email, contactNO, whatsappNO, CompanyName);

                NOofStudentR4++; // Increment in Number of student who passed in Round 4
            }

            cout << "<----Successfully Data Fatched From the Round4's File \n";
        }
    }

    //--------------------------------------------------------------------------------------------------------------------->
    //---------------------------------------Function to Read Final Round's File------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void ReadFileForFinalRound(const string &filepath, const string &CompanyName)
    {

        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << "\nError in Opening Final Round's File\nPlease Try again with valid File Path :) \n";
            return;
        }
        else
        {

            cout << "\nFatching Data from The Final Round's File---->\n";

            string line;

            getline(file, line); // Skip the first line

            while (getline(file, line))
            {
                stringstream ss(line);

                //--->Extract data from each line

                // Variables to Extact Data

                string WordToSkip; // To Skip Unnecessary data

                string id_str, name, program, batch_str, email, conatctNO_str, whatsappNO_str, pakage_str;
                int batch;
                long long id, contactNO, whatsappNO;
                float pakage;

                getline(ss, WordToSkip, ','); // Ignore the Sr No.
                getline(ss, id_str, ',');
                id = stoll(id_str);
                getline(ss, name, ',');
                getline(ss, program, ',');
                getline(ss, batch_str, ',');
                batch = stoi(batch_str);
                getline(ss, WordToSkip, ','); // Igonre Interview Date
                getline(ss, email, ',');
                getline(ss, conatctNO_str, ',');
                contactNO = stoll(conatctNO_str);
                getline(ss, whatsappNO_str, ',');
                whatsappNO = stoll(whatsappNO_str);
                getline(ss, pakage_str, ',');
                pakage = stof(pakage_str);

                // Insert the extracted data into the list

                addToListFR(id, name, batch, program, email, contactNO, whatsappNO, CompanyName, pakage);

                NOofStudentFR++;        // Increment in Number of student who passed in Final Round
                TotalPakages += pakage; // Increment in Total Amount of Pakage Offered
            }

            cout << "<----Successfully Data Fatched From the Final Round's File \n";
        }
    }

public:
    //--------------------------------------------------------------------------------------------------------------------->
    //---------------------------------------Function to Input Data -------------------------------------------------------->
    //--------------------------------------------------------------------------------------------------------------------->

    void InputData()
    {
        string CompanyName;
        cout << "\nEnter Company's Name : ";
        cin >> CompanyName;

        string filepath;
        cout << "\nEnter File Path for Round 1's file : ";
        cin >> filepath;
        ReadFileForRound1(filepath, CompanyName); // Collect Data From Round1's File

        cout << "\nEnter File Path for Round 2's file : ";
        cin >> filepath;
        ReadFileForRound2(filepath, CompanyName); // Collect Data From Round2's File

        cout << "\nEnter File Path for Round 3's file : ";
        cin >> filepath;
        ReadFileForRound3(filepath, CompanyName); // Collect Data From Round3's File

        cout << "\nEnter File Path for Round 4's file : ";
        cin >> filepath;
        ReadFileForRound4(filepath, CompanyName); // Collect Data From Round4's File

        cout << "\nEnter File Path for Final Round's file : ";
        cin >> filepath;
        ReadFileForFinalRound(filepath, CompanyName); // Collect Data From Final Round's File
    }
};