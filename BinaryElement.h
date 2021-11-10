#pragma once
class binaryElement
{
public:
	binaryElement(int k) : key(k), left(nullptr), right(nullptr) {};
	int key;
	binaryElement* left;
	binaryElement* right;
};
