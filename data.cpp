//
// Created by phinease on 12/11/2019.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0){
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x]){
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0){
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x]){
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j){
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

void loadData(string fn, vector< vector<int> > &pts, vector< vector<int> > &ranks){
    string rankspts = "data/rankspts.csv";
    ifstream read;

    read.open(fn,ifstream::out);

    if(read.is_open()){
        fprintf( stderr, "File ./%s is open.\n", fn.c_str());
    } else {
        fprintf( stderr, "Failed to open %s\n", fn.c_str());
    }

    string line;
    while(!read.eof()){
        //read data from file
        //getchar();
        std::getline (read,line);
        vector<string> result;
        vector<int> p;
        vector<int> r;
        result = split(line, ",");
        /*
        int temp = 0;
        for (auto & i : result) {
            temp ++;
            fprintf( stdout, "%12s\t", i.c_str());
        }
        cout << endl;
        */


        for (int i = 0; i < result.size()/6 ; ++i) {
            r.push_back(stoi(result[1+i*6]));
            p.push_back(stoi(result[2+i*6]));
        }
        pts.push_back(p);
        ranks.push_back(r);
        // cout << "number: " << temp << endl;

    }

    read.close();
}