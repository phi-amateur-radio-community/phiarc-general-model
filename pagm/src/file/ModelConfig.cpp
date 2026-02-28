// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/ModelConfig.cpp
// Configuration reader and writer.

#include <iostream>
#include <fstream>
#include <charconv>
#include "model/Transformer.cpp"

using namespace std;

Transformer createTransformer(const string& path) {
	ifstream file(path);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << path << endl;
		exit(1);
	}
}

Transformer loadTransformer(const string& path)
{
	ifstream file(path);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << path << endl;
		exit(1);
	}
}

int parsePara(const string& str) {
	int value = 0;
	auto pos = str.find(' ');
	from_chars(str.data(), str.data() + pos, value);
	return value;
}