#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

/*std::string to_string_with_precision(double value, int precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}*/
//===================================
//== Field class definition :
//== consists Field name,type,is_array
//===================================
class Field{

    private:
    // private member data
        string name;
        string type;
        bool is_array;

    public:
        // parameter constructor since a Field object must have private members given beforehand
        Field(string newname, string newtype, bool isarr){
            name = newname;
            type = newtype;
            is_array = isarr;
        }
        // basic getters
        string getType(){
            return type;
        }
        string getName(){
            return name;
        }
        bool isArray(){
            if(is_array){
                return 1;
            }
            return 0;
        }
        // basic setters
        void setType(string type){
            type = type;
        }
        void setName(string name){
            name = name;
        }
        void setArr(bool isarr){
            is_array = isarr;
        }

};

/*
integer class defined to keep track of the objects that are integer
*/
class integer : public Field{

    private:
        // private data members
        int value;
    public:
        // parametered constructor because it has to have the values initialized
        integer(string name, string type, bool isarr, int value) 
        : Field(name, type, isarr), value(value) {}
        // basic getter
        int getValue(){
            return value;
        }
        // basic setter
        void setValue(int value){
            value = value;
        }
        // operative overload
        bool operator>(integer& other){
        return this->value > other.value;
        }
        bool operator==(integer& other){
        return this->value == other.value;
        }
};
/*
double field objects class double_
*/
class double_ : public Field{

    private:
        double value;
    public:
        // parametered constructor
        double_(string name, string type, bool isarr, double value) 
        : Field(name, type, isarr), value(value) {}
        // basic getter
        double getValue(){
            return value;
        }
        // basic setter
        void setValue(double value){
            value = value;
        }
};
/*
char_ class to keep track of field objects that are char
*/
class char_ : public Field {

    private:
        // private member data
        char value;

    public:
        // parameter class constructor
        char_(string name, string type, bool isarr, char value) 
            : Field(name, type, isarr), value(value) {}
        // basic getter
        char getValue() {
            return value;
        }
        // basic setter
        void setValue(char value) {
            value = value;
        }
};
/*
String_ class to keep track of field object that are string
*/
class String_ : public Field{
    
    private:
        // private member data
        string s;
    public:
        // parameter class constructor
        String_(string name, string type, bool isarr, string s) 
        : Field(name, type, isarr), s(s) {}
        // basic getter
        string getStr(){
            return s;
        }
        // basic setter
        void setStr(string set){
            s = set;
        }
        // overloaded operators
        bool operator==(String_& other) {
            return s == other.s;
        }
        bool operator>(const String_& other) const {
            return this->s > other.s;
        }
};
/* ===========================================================
// Field Array class keeps track of the all field objects, manipulates them
// stores them, searches them , sorts them, its the general structure to 
// apply commands to entries
// =========================================================== */
class FieldArray{
    // to print the field array incase i need overloaded friend operator
    friend ostream& operator<<(ostream& os, FieldArray& fa);
    // friend classes
    friend class Field;     

    private:
        // private member data
        vector<String_> strings;
        vector<integer> integers;
        vector<char_> chars;
        vector<double_> doubles;
    public:
        // default constructor
        FieldArray() {}
        // basic adding to list functions
        void addString(String_ object){
            strings.push_back(object);
        }
        void addInt(integer object){
            integers.push_back(object);
        }
        void addChars(char_ object){
            chars.push_back(object);
        }
        void addDoubles(double_ object){
            doubles.push_back(object);
        }
        // SEARCH: it searches the given string in the field objects currently existing
        // and then returns if the string is valid and exists on the entries
        string search(string name, string field){
                
                int i;
                bool found = false;
                // the loop to go through string elements
                for(i = 0; i < strings.size(); i++){
                    // check if the field matches
                    if(strings[i].getName() == field){
                        // check if the name matches or is included in the object
                        if (strings[i].getStr().find(name) != std::string::npos) {
                            // return if it exists
                            return strings[i].getStr();
                        }
                    }
                    
                }  
                // same thing for the integers    
                for(i = 0; i < integers.size(); i++){
                    if(integers[i].getName() == field){

                        if(integers[i].getValue() == stoi(name))
                        {
                            return to_string(integers[i].getValue());
                            
                        }

                    }
                }
                // same thing for the doubles
                       
                for(i = 0; i < doubles.size(); i++){
                    if(doubles[i].getName() == field){

                        if(doubles[i].getValue() == stod(name))
                        {
                            return to_string(doubles[i].getValue());
                           
                        }

                    }
                }
                // same thing for the chars       
                for(i = 0; i < chars.size(); i++){
                    if(chars[i].getName() == field){

                        if(chars[i].getValue() == name[0])
                        {
                            return to_string(chars[i].getValue());
                            
                        }

                    }
                }     
                // exception to print to log file      
                return ("Exception: Couldnt find the entry");
                
        }
        /* =====================================================
        // Sort function to sort the items based on Alphabet for strings, chars
        // value for integers and doubles
        ===================================================== */
        vector<string> sortEntries(string name, string type, vector<string> entries){
            // if the type is string
            if(type == "string"){
                // temporary string array to take all the values into the list
                vector<string> temp;
                for(int i = 0; i < strings.size(); i++){
                    if(strings[i].getName() == name){
                        // if the Field name matches the objects gets included to the list
                        temp.push_back(strings[i].getStr());
                    }
                }
                // bubble sort the array
                int n = temp.size();
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (temp[j] > temp[j + 1]) {
                            swap(temp[j], temp[j + 1]);
                        }
                    }
                }
                // list the entries based on the sorting qualification
                for(int j = 0 ; j < temp.size(); j++){
                    for(int i = 0; i < entries.size() ; i++){
                        size_t found = entries[i].find(temp[j]);
                        if(found != std::string::npos){
                            string temp;                                       
                            temp = entries[j];
                            entries[j] = entries[i];
                            entries[i] = temp;                                       
                        }                                 
                    }                        
                }  
            // same thing for integers                                       
            }else if(type == "integer"){
                vector<int> temp;
                for(int i = 0; i < integers.size(); i++){
                    if(integers[i].getName() == name){
                        temp.push_back(integers[i].getValue());
                    }
                }
                
                int n = temp.size();
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (temp[j] > temp[j + 1]) {
                            swap(temp[j], temp[j + 1]);
                        }
                    }
                }

                for(int j = 0 ; j < temp.size(); j++){
                    for(int i = 0; i < entries.size() ; i++){
                        size_t found = entries[i].find(to_string(temp[j]));
                        if(found != std::string::npos){
                            string temp;                                       
                            temp = entries[j];
                            entries[j] = entries[i];
                            entries[i] = temp;
                        }                                 
                    }                        
                }                                         
            }
            else if(type == "char"){
                vector<char> temp;
                for(int i = 0; i < chars.size(); i++){
                    if(chars[i].getName() == name){
                        temp.push_back(chars[i].getValue());
                    }
                }
                
                int n = temp.size();
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (temp[j] > temp[j + 1]) {
                            swap(temp[j], temp[j + 1]);
                        }
                    }
                }

                for(int j = 0 ; j < temp.size(); j++){
                    for(int i = 0; i < entries.size() ; i++){
                        size_t found = entries[i].find(to_string(temp[j]));
                        if(found != std::string::npos){
                            string temp;                                       
                            temp = entries[j];
                            entries[j] = entries[i];
                            entries[i] = temp;
                        }                                 
                    }                        
                }                                         
            }
            else if(type == "double"){
               
                vector<double> temp;
                for(int i = 0; i < doubles.size(); i++){
                    if(doubles[i].getName() == name){                      
                        temp.push_back(doubles[i].getValue());
                    }
                }                
                int n = temp.size();
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (temp[j] > temp[j + 1]) {
                            swap(temp[j], temp[j + 1]);
                        }
                    }
                }
                for(int j = 0 ; j < temp.size(); j++){
                    for(int i = 0; i < entries.size() ; i++){                     
                        size_t found = entries[i].find(to_string(temp[j]));
                        if(found != std::string::npos){
                            string temp;                                       
                            temp = entries[j];
                            entries[j] = entries[i];
                            entries[i] = temp;
                        }else{
                        }                                
                    }                        
                }                                         
            }
            return entries;
        }

};
// overloaded << operator for field array incase i need
ostream& operator<<(ostream& os, FieldArray& fa) {
    for (vector<String_>::iterator it = fa.strings.begin(); it != fa.strings.end(); ++it) {
        os << it->getStr() << " - ";
    }
    os << endl;

    for (vector<integer>::iterator it = fa.integers.begin(); it != fa.integers.end(); ++it) {
        os << it->getValue() << " ";
    }
    os << endl;

    for (vector<char_>::iterator it = fa.chars.begin(); it != fa.chars.end(); ++it) {
        os << it->getValue() << " ";
    }
    os << endl;

    for (vector<double_>::iterator it = fa.doubles.begin(); it != fa.doubles.end(); ++it) {
        os << it->getValue() << " ";
    }
    os << endl;

    return os;
}
// split function to help me with the multi strings that are seperated by ':'
vector<string> split(string& str) {
    vector<string> substrings;
    string token;
    istringstream tokenStream(str);
    // takes the line till it sees ':'
    while (getline(tokenStream, token, ':')) {
        // adds seperated string to the vector
        substrings.push_back(token);
    }
    // returns the vector
    return substrings;
}

int main(){
    // file pointer
    ifstream fp("data.txt");
    if (!fp.is_open()) {
        throw invalid_argument("Failed to open the file");
    }
    // field array of all objects
    FieldArray total;
    // getline string
    string line;
    // fields
    vector<Field> fields;
    // parameters
    int parameters = 0;
    // Read the first line
    int count_ = 0;
    int count2 = 0;
    ofstream outfile("output.txt");
    if (getline(fp, line)) {
        // turn into stream object
        stringstream ss(line);
        // substring
        string segment;
        // read until you see the '|'
        count_ = std::count(line.begin(), line.end(), '|') + 1;
        while (getline(ss, segment, '|')) {
    
            stringstream partialStream(segment);
            string field_name, field_type, is_array_str;
            bool is_array = false;
                // read the fields name type and is array or not
            if (getline(partialStream, field_name, ':') &&
                getline(partialStream, field_type, ':') &&
                getline(partialStream, is_array_str, ':')) {
                    for(int i = 0; i < fields.size(); i++){
                        // if the parameter already exists
                        if(fields[i].getName() == field_name){
                            throw runtime_error("Exception: Existing parameter");
                        }
                    }

                if (is_array_str == "multi") {
                    is_array = true;
                }
                // put the values into the fields vector
                fields.emplace_back(field_name, field_type, is_array);
                count2++;
            } else {
                outfile << "Exception: wrong file format" << segment << endl;
            }
        }
    }
    // first line to see the fields in output.txt
    outfile << line << endl;
    // object count
    int objCount = 0;
    // entries
    vector<string> entries;
    // substrings we need later
    vector<string> substrings;
    // read the data lines
    bool flag = false;
    while (getline(fp, line)) {
        stringstream ss(line);
        string data;
        flag = false;
        int field_index = 0;
        // if there is already an existing object of an entry
        for(int i = 0;i < entries.size(); i++){
            if(line == entries[i]){
                flag = true;
            }
        }
        // count the amount of '|' to see the parameters
        if(count(line.begin(), line.end(), '|') != count_ - 1){
            outfile << "Exception: Missing field" << endl << line << endl;
        }
        else if(flag){

            outfile << "Exception: Duplicate entry" << endl << line << endl;        
        }else{

            // read all the data in a loop
            while (getline(ss, data, '|')) {
                // if within the field size
                if (field_index < fields.size()) {
                    Field& field = fields[field_index];
                    // read the type
                    if (field.getType() == "string") {
                            // check if its an array
                            if(field.isArray()){
                                // split the data to multiple objects
                                substrings = split(data);
                                // create each object
                                for(int i = 0; i < substrings.size(); i++){
                                    String_ strTemp(field.getName(), field.getType(), field.isArray(), substrings[i]);
                                    total.addString(strTemp);                                
                                }
                                // clear the temp array for next time
                                substrings.clear();
                            }else{
                                // just create 1 object
                                String_ strTemp(field.getName(), field.getType(), field.isArray(), data);

                                total.addString(strTemp);
                               
                            }   
                    // same for integers          
                    } else if (field.getType() == "integer") {
                        if(field.isArray()){
                            substrings = split(data);
                            for(int i = 0; i < substrings.size(); i++){
                                    integer intTemp(field.getName(), field.getType(), field.isArray(), stoi(substrings[i]));                 
                                    total.addInt(intTemp);
                                   
                                }
                        }else{
                            integer intTemp(field.getName(), field.getType(), field.isArray(), stoi(data));
                            total.addInt(intTemp);
                            
                        }
                        
                    } else if (field.getType() == "double") {
                        if(field.isArray()){
                            substrings = split(data);
                            for(int i = 0; i < substrings.size(); i++){
                                    double_ doubleTemp(field.getName(), field.getType(), field.isArray(), stod(substrings[i]));                       
                                    total.addDoubles(doubleTemp);
                                    
                                }
                        }else{
                            double_ doubleTemp(field.getName(), field.getType(), field.isArray(), stod(data));                       
                            total.addDoubles(doubleTemp);
                         
                        }
                        
                    } else if (field.getType() == "char") {
                        if(field.isArray()){
                            substrings = split(data);
                            for(int i = 0; i < substrings.size(); i++){
                                    char_ charTemp(field.getName(), field.getType(), field.isArray(), substrings[i][0]);
                                    total.addChars(charTemp);
                                   
                                }
                        }else{
                            char_ charTemp(field.getName(), field.getType(), field.isArray(), data[0]);
                            total.addChars(charTemp);
                          
                        }
                    }else{
                        
                    }

                    objCount++;
                }
                field_index++;
            }

            entries.push_back(line);
        }      
    }
    string type_;
    // count of the unique entries
    outfile << entries.size() << " Unique entries" << endl;
    ifstream commands("commands.txt");
    if (!outfile.is_open()){
        cout << "Failed to open the file for writing" << endl;
        return 0;
    }
        if(!commands.is_open()){
            cout << "Failed to open the file for writing" << endl;
            return 0;
        }else{
            // read the command
            string command;
            while (getline(commands, command)) {
                stringstream sss(command);
                string action, name, asd;

                (getline(sss, action, ' '));
                        // if the command is search
                    if (action == "search") {
                        outfile << command << endl;
                        getline(sss, name, ' ');
                        getline(sss, asd,' ');
                       try {
                            // if the command is a two word like Led:Zeppelin
                            for (char& c : name) {
                                if (c == ':') {
                                    c = ' ';
                                }
                            } 
                            // search for the word                                          
                            string result = total.search(name, asd);
                            // find the word in the string we received
                            if(result.find(name) != std::string::npos){
                                for(int i = 0; i < entries.size() ; i++){
                                    size_t found = entries[i].find(name);
                                    if(found != std::string::npos){
                                        
                                        outfile << entries[i] << endl;
                                    }                                 
                                }  
                            //                         
                            }else{
                                outfile << result << endl;
                            }                          
                        } catch (const invalid_argument& e) {
                            outfile << e.what() << endl;
                        }
                    }
                    // if the command is sort
                    else if (action == "sort"){
                        outfile << command << endl;
                        getline(sss, name, ' ');
                        try {
                            // flag to keep track if the parameter exists
                            bool flag2 = true;
                            // toPrint the entries sorted version
                            vector<string> toPrint;
                            for(int i = 0 ;i < fields.size(); i++){
                                if(fields[i].getName() == name){
                                    type_ = fields[i].getType();
                                    flag2 = false;
                                    break;
                                }
                            }
                            if(flag2){  
                                // no such parameter exists                             
                                outfile << "Exception: Wrong parameter to sort" << endl;
                            }else{
                                // sort the entries and print
                                toPrint = total.sortEntries(name,type_,entries);
                                for(int i = 0; i < toPrint.size(); i++){
                                    outfile << toPrint[i] << endl;
                                }  
                            }                           
                        } catch (const invalid_argument& e) {
                            outfile << e.what() << endl;
                            cout << e.what() << endl;
                        }
                    }else{
                        outfile << "Exception: non matching command Terminating..." << endl;
                        throw invalid_argument("Command.txt non matching command terminating...");
                    }     
            }       
        }

     outfile.close();
           
    return 0;
}
    