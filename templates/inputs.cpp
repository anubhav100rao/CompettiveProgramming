#include "template.cpp"

vector<ll> parseLine(string &line) {
    vector<ll> v;
    stringstream tmp(line);
    string word;
    while (getline(tmp, word, ' ')) {
        v.push_back(stoi(word));
    }
    return v;
}
