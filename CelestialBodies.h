#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

// Class Hierarchy

class CelestialBody {
public:
	CelestialBody(std::string newName, std::string newInfo, double newMass);

	std::string getName();
	void setName(std::string newName);

	std::string getInfo();
	void setInfo(std::string newInfo);

	double getMass();
	void setMass(double newMass);

	std::string getTypeDescription();
	void setTypeDescription(std::string newTypeDescription);

	virtual std::string getData() = 0;

private:
	std::string name;
	std::string info;	// about the perticular celestial body
	std::string typeDescription;	// of its specific subtype (GasGiant, Dwarf, MinorMoon, etc.)
	double mass;	// in Earth masses for planets and satellites and in Solar masses for Stars
};

static std::vector<CelestialBody*> celVec;	// class instance container

// Forward declarations
class Planet;
class Satellite;

// Stars

class Star : public CelestialBody {
public:
	Star(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);

	std::string getData();

	double getRadius();
	void setRadius(double newRadius);

	double getTemperature();
	void setTemperature(double newTemperature);

	char getSpectralType();
	void setSpectralType(char newSpectralType);

	std::string getLuminosity();
	void setLuminosity(std::string newLuminosity);

private:
	double radius;	// in Solar Radii
	double temperature;	// in Kelvin
	char spectralType;
	std::string luminosity;	// from I to VII
};

class Supergiant : public Star {
public:
	Supergiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Brightgiant : public Star {
public:
	Brightgiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Giant : public Star {
public:
	Giant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Subgiant : public Star {
public:
	Subgiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Dwarf : public Star {
public:
	Dwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Subdwarf : public Star {
public:
	Subdwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

class Whitedwarf : public Star {
public:
	Whitedwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType);
};

// Planets

class Planet : public CelestialBody {
public:
	Planet(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity);
	Planet(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, Satellite* newSatellite);
	Planet(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, std::vector<Satellite*> newSatellites);

	std::string getData();

	double getOrbitalPeriod();
	void setOrbitalPeriod(double newOrbitalPeriod);

	double getRadius();
	void setRadius(double newRadius);

	double getGravity();
	void setGravity(double newGravity);

private:
	double orbitalPeriod;	//in days
	double radius;	//in km
	double gravity;	//in m/s^2
};

class GasGiant : public Planet {
public:
	GasGiant(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity);
};

class SuperEarth : public Planet {
public:
	SuperEarth(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity);
};

class NeptuneLike : public Planet {
public:
	NeptuneLike(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity);
};

class Terrestrial : public Planet {
public:
	Terrestrial(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity);
};

// Satellites

class Satellite : public CelestialBody {
public:
	Satellite(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, CelestialBody * newPlanet);

	std::string getData();

	double getOrbitalPeriod();
	void setOrbitalPeriod(double newOrbitalPeriod);

	double getRadius();
	void setRadius(double newRadius);

	double getGravity();
	void setGravity(double newGravity);

	std::string getPlanetName();
	void setPlanet(CelestialBody* newPlanet);

private:
	double orbitalPeriod;	//in days
	double radius;	//in km
	double gravity;	//in m/s^2
	CelestialBody* planet;

	friend class Planet;
};

class MajorMoon : public Satellite {
public:
	MajorMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, 
		CelestialBody* newPlanet);
};

class IntermediateMoon : public Satellite {
public:
	IntermediateMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, 
		CelestialBody* newPlanet);
};

class MinorMoon : public Satellite {
public:
	MinorMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, 
		CelestialBody* newPlanet);
};

// Vector

static std::vector<CelestialBody*> celestialVector;

// Vector Functions

void starInput(std::ifstream& input, std::string& newName, std::string& newInfo, std::string& newSpectralTypeStr, double& newMass, double& newRadius,
	double& newTemperature, char& newSpectralType);
void planetoidInput(std::ifstream& input, std::string& newName, std::string& newInfo, double& newMass, double& newOrbitalPeriod, double& newRadius,
	double& newGravity);
void initCelVec();	// function to add the initial entries into the "wiki"
void printCelVec();
bool BMPattern(std::string pattern, std::string text);	// Boyer-Moore SPM function
void searchCelVec(std::string pattern);
CelestialBody& findEntry(std::string pattern);
void sortAlphabetically();
void sortByMass();

// Program Navigation Functions

void programIntro();
void search();
void displayAlph();
void displayByMass();
void add();

void addStar();
void addPlanet();
void addSatellite();

void getStarParams(std::string& newName, std::string& newInfo, std::string& newSpectralTypeStr, double& newMass, double& newRadius, 
	double& newTemperature, char& newSpectralType);
void getPlanetoidParams(std::string& newName, std::string& newInfo, double& newMass, double& newOrbitalPeriod, double& newRadius,
	double& newGravity);

void addSupergiant();
void addBrightgiant();
void addGiant();
void addSubgiant();
void addDwarf();
void addSubdwarf();
void addWhitedwarf();

void addGasGiant();
void addSuperEarth();
void addNeptuneLike();
void addTerrestrial();

void addMajorMoon();
void addIntermediateMoon();
void addMinorMoon();

void finalExit();