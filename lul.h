#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <vector>
#include <cstdlib>
#include <zip.h>
#include <thread>
#include <chrono>
#include <cstdio>

void task_1();
void cake();
void task_2();

void makeData(std::string filename);
void makeFiles();
void makeData(std::string filename);
void createZip();
void readZip(int &numFiles, double summ, std::string archieveName, std::vector<double>& arithmeticMean);
void addNumber(int count, double summ, std::vector<int> numbers, std::vector<double>& arithmeticMean);
void printResult(const std::string& filename, int numFiles);
void secreteFunction();
void task_3();

void task_4();
