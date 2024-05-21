#include "CelestialBodies.h"

CelestialBody::CelestialBody(std::string newName, std::string newInfo, double newMass)
{
    setName(newName);
    setInfo(newInfo);
    setMass(newMass);
    celVec.push_back(this);
}

std::string CelestialBody::getName()
{
    return name;
}

void CelestialBody::setName(std::string newName)
{
    name = newName;
}

std::string CelestialBody::getInfo()
{
    return info;
}

void CelestialBody::setInfo(std::string newInfo)
{
    info = newInfo;
}

double CelestialBody::getMass()
{
    return mass;
}

void CelestialBody::setMass(double newMass)
{
    if (newMass > 0)
        mass = newMass;
    else {
        std::cout << "Invalid mass, setting mass to 1 kg\n";
        mass = 1;
    }
        
}

std::string CelestialBody::getTypeDescription()
{
    return typeDescription;
}

void CelestialBody::setTypeDescription(std::string newTypeDescription)
{
    typeDescription = newTypeDescription;
}

Star::Star(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : CelestialBody(newName, newInfo, 
    newMass)
{
    setRadius(newRadius);
    setTemperature(newTemperature);
    setSpectralType(newSpectralType);
}

double Star::getRadius()
{
    return radius;
}

void Star::setRadius(double newRadius)
{
    if (newRadius > 0)
        radius = newRadius;
    else {
        std::cout << "Invalid radius, setting to 1 solar radii\n";
        radius = 1;
    }
}

double Star::getTemperature()
{
    return temperature;
}

void Star::setTemperature(double newTemperature)
{
    if (newTemperature > 0)
        temperature = newTemperature;
    else {
        std::cout << "Invalid temperature, setting to 0 K\n";
        temperature = 0;
    }
}

char Star::getSpectralType()
{
    return spectralType;
}

void Star::setSpectralType(char newSpectralType)
{
    if (newSpectralType == 'O' || newSpectralType == 'B' || newSpectralType == 'A' || newSpectralType == 'F' || newSpectralType == 'G' || newSpectralType == 'K' || 
        newSpectralType == 'M')
        spectralType = newSpectralType;
    else {
        std::cout << "Invalid spectral type, setting to M\n";
        spectralType = 'M';
    }
}

void Star::setLuminosity(std::string newLuminosity)
{
    if (newLuminosity == "I" || newLuminosity == "II" || newLuminosity == "III" || newLuminosity == "IV" || newLuminosity == "V" || newLuminosity == "VI"
        || newLuminosity == "VII")
        luminosity = newLuminosity;
    else {
        std::cout << "Invalid luminosity, setting to I\n";
        luminosity = "I";
    }
}

std::string Star::getLuminosity()
{
    return luminosity;
}

std::string Star::getData() 
{
    std::string data = "";
    data += "Name: " + getName() + "\n";
    data += getTypeDescription();
    data += "Info: " + getInfo() + "\n";
    data += "Mass: " + std::to_string(getMass()) + "\n";
    data += "Radius: " + std::to_string(getRadius()) + "\n";
    data += "Temperature: " + std::to_string(getTemperature()) + "\n";
    std::string specT = "";
    specT += getSpectralType();
    data += "Spectral type: " + specT + "\n";
    data += "Luminosity: " + getLuminosity() + "\n\n";
    return data;
}

Supergiant::Supergiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo,
    newMass, newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Supergiant\n"
        "Supergiant stars are extremely massive and luminous stars that are in the late stages of their evolution. They are among the largest stars in the\n" 
        "universe and are characterized by their immense size and high brightness. Supergiants typically have a short lifespan compared to smaller stars and\n"
        "often end their lives in dramatic supernova explosions or collapse into black holes or neutron stars.\n");
    setLuminosity("I");
}

Brightgiant::Brightgiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, 
    newInfo, newMass, newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Bright giant\n"
        "Bright giant stars are relatively massive and luminous stars that are larger and brighter than main-sequence stars like our Sun. They are in an \n"
        "advanced stage of their evolution, having exhausted their core hydrogen fuel. Bright giants are characterized by their increased size and brightness\n"
        "but are not as massive or luminous as supergiant stars.\n");
    setLuminosity("II");
}

Giant::Giant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo, newMass, 
    newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Giant\n"
        "Giant stars are intermediate-mass stars in an advanced stage of their evolution. They have expanded and become much larger than main-sequence stars,\n"
        "such as our Sun. Giant stars are characterized by their increased size and luminosity, often due to the fusion of helium in their cores.\n");
    setLuminosity("III");
}

Subgiant::Subgiant(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo, 
    newMass, newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Subgiant\n"
        "Subgiant stars are transitional stars that have left the main-sequence phase and are starting to evolve into giant stars. They are slightly larger\n"
        "and more luminous than main - sequence stars of similar mass, undergoing changes as they progress in their stellar lifecycle.\n");
    setLuminosity("IV");
}

Dwarf::Dwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo, newMass, 
    newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Dwarf\n"
        "Dwarf stars, also known as main-sequence stars, are common, relatively small stars that are in a stable phase of their evolution. They generate\n"
        "energy through hydrogen fusion in their cores and make up the majority of stars in the universe, including our Sun.\n");
    setLuminosity("V");
}

Subdwarf::Subdwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo, 
    newMass, newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Subdwarf\n"
        "Subdwarf stars are smaller and less luminous than main-sequence stars of the same spectral type. They are often found in the halo of a galaxy and are\n"
        "characterized by their lower luminosity and metallicity, indicating older age and different evolutionary history.\n");
    setLuminosity("VI");
}

Whitedwarf::Whitedwarf(std::string newName, std::string newInfo, double newMass, double newRadius, double newTemperature, char newSpectralType) : Star(newName, newInfo,
    newMass, newRadius, newTemperature, newSpectralType)
{
    setTypeDescription("Class: Star\nType: Whitedwarf\n"
        "White dwarf stars are the remnants of low- to medium-mass stars that have exhausted their nuclear fuel. They are extremely dense, with mass comparable\n"
        "to the Sun but condensed into a volume roughly the size of Earth. White dwarfs no longer undergo fusion and slowly cool down over billions of years,\n"
        "eventually becoming cold, dark objects.\n");
    setLuminosity("VII");
}

Planet::Planet(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity) : CelestialBody(newName, 
    newInfo, newMass)
{
    setOrbitalPeriod(newOrbitalPeriod);
    setRadius(newRadius);
    setGravity(newGravity);
}

std::string Planet::getData()
{
    std::string data = "";
    data += "Name: " + getName() + "\n";
    data += getTypeDescription();
    data += "Info: " + getInfo() + "\n";
    data += "Mass: " + std::to_string(getMass()) + "\n";
    data += "Orbital period: " + std::to_string(getOrbitalPeriod()) + "\n";
    data += "Radius: " + std::to_string(getRadius()) + "\n";
    data += "Gravity: " + std::to_string(getGravity()) + "\n\n";
    return data;
}

double Planet::getOrbitalPeriod()
{
    return orbitalPeriod;
}

void Planet::setOrbitalPeriod(double newOrbitalPeriod)
{
    if (newOrbitalPeriod > 0)
        orbitalPeriod = newOrbitalPeriod;
    else {
        std::cout << "Invalid orbital period, setting to 1\n";
        orbitalPeriod = 1;
    }
}

double Planet::getRadius()
{
    return radius;
}

void Planet::setRadius(double newRadius)
{
    if (newRadius > 0)
        radius = newRadius;
    else {
        std::cout << "Invalid radius, setting to 1\n";
        radius = 1;
    }
}

double Planet::getGravity()
{
    return gravity;
}

void Planet::setGravity(double newGravity)
{
    if (newGravity > 0)
        gravity = newGravity;
    else {
        std::cout << "Invalid gravity, setting to M\n";
        gravity = 1;
    }
}

GasGiant::GasGiant(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity) : Planet(newName, newInfo, 
    newMass, newOrbitalPeriod, newRadius, newGravity) {
    setTypeDescription("Class: Planet\nType: Gas Giant\n"
        "Gas giants, exemplified by Jupiter and Saturn, are immense planets predominantly composed of hydrogen and helium. Unlike terrestrial planets, they\n"
        "lack solid surfaces, boasting thick atmospheres marked by dynamic cloud formations. Their substantial mass and powerful magnetic fields distinguish\n"
        "them in our solar system.\n");
}

SuperEarth::SuperEarth(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity) : Planet(newName,
    newInfo, newMass, newOrbitalPeriod, newRadius, newGravity) {
    setTypeDescription("Class: Planet\nType: Super-Earth\n"
        "Super-Earths are larger than Earth but smaller than gas giants, these planets have masses greater than Earth's and may possess diverse compositions,\n"
        "potentially including rocky surfaces and thick atmospheres.\n");
}

NeptuneLike::NeptuneLike(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity): Planet(newName,
    newInfo, newMass, newOrbitalPeriod, newRadius, newGravity) {
    setTypeDescription("Class: Planet\nType: Neptune-like\n"
        "Neptune-like planets are ice giants resembling Neptune, characterized by a substantial atmosphere rich in ices and volatile compounds. They typically\n"
        "have intermediate masses and are part of the broader category of exoplanets.\n");
}

Terrestrial::Terrestrial(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity) : Planet(newName, 
    newInfo, newMass, newOrbitalPeriod, newRadius, newGravity) {
    setTypeDescription("Class: Planet\nType: Terrestrial\n"
        "Terrestrial planets are rocky celestial bodies with solid surfaces, distinguishing them from gas giants and ice giants. These planets, including\n"
        "Earth, have relatively thin atmospheres and are characterized by diverse geological features such as mountains, valleys, and plains.\n");
}

Satellite::Satellite(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, CelestialBody* newPlanet) 
    : CelestialBody(newName, newInfo, newMass) {
    setOrbitalPeriod(newOrbitalPeriod);
    setRadius(newRadius);
    setGravity(newGravity);
    setPlanet(newPlanet);
}

std::string Satellite::getData() {
    std::string data = "";
    data += "Name: " + getName() + "\n";
    data += getTypeDescription();
    data += "Planet: " + getPlanetName() + "\n";
    data += "Info: " + getInfo() + "\n";
    data += "Mass: " + std::to_string(getMass()) + "\n";
    data += "Orbital period: " + std::to_string(getOrbitalPeriod()) + "\n";
    data += "Radius: " + std::to_string(getRadius()) + "\n";
    data += "Gravity: " + std::to_string(getGravity()) + "\n\n";
    return data;
}

double Satellite::getOrbitalPeriod()
{
    return orbitalPeriod;
}

void Satellite::setOrbitalPeriod(double newOrbitalPeriod)
{
    if (newOrbitalPeriod > 0)
        orbitalPeriod = newOrbitalPeriod;
    else {
        std::cout << "Invalid orbital period, setting to 1\n";
        orbitalPeriod = 1;
    }
}

double Satellite::getRadius()
{
    return radius;
}

void Satellite::setRadius(double newRadius)
{
    if (newRadius > 0)
        radius = newRadius;
    else {
        std::cout << "Invalid radius, setting to 1\n";
        radius = 1;
    }
}

double Satellite::getGravity()
{
    return gravity;
}

void Satellite::setGravity(double newGravity)
{
    if (newGravity > 0)
        gravity = newGravity;
    else {
        std::cout << "Invalid gravity, setting to M\n";
        gravity = 1;
    }
}

void Satellite::setPlanet(CelestialBody* newPlanet)
{
    planet = newPlanet;
}

std::string Satellite::getPlanetName()
{
    return planet->getName();
}

MajorMoon::MajorMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, CelestialBody* newPlanet) 
    : Satellite(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, newPlanet)
{
    setTypeDescription("Class: Natural Satellite\nType: Major Moon\n"
        "Major moons, substantial in size and mass, orbit planets with stability, shaping planetary systems through gravitational influence. These celestial\n"
        "bodies showcase diverse geological landscapes, intriguing scientists with the possibility of unique environments and crucial insights into planetary\n"
        "evolution beyond Earth.\n");
}

IntermediateMoon::IntermediateMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, 
    CelestialBody* newPlanet) : Satellite(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, newPlanet)
{
    setTypeDescription("Class: Natural Satellite\nType: Intermediate Moon\n"
        "Intermediate moons are mid-sized natural satellites, smaller than major moons but larger than the smallest ones. They possess moderate mass and may\n"
        "exhibit various geological features, orbiting their parent planets in relatively stable paths.\n");
}

MinorMoon::MinorMoon(std::string newName, std::string newInfo, double newMass, double newOrbitalPeriod, double newRadius, double newGravity, CelestialBody* newPlanet) 
    : Satellite(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, newPlanet)
{
    setTypeDescription("Class: Natural Satellite\nType: Minor Moon\n"
        "Minor moons are smaller natural satellites, often irregularly shaped, with lower mass compared to major and intermediate moons. They might have more\n"
        "eccentric orbits and fewer defined geological features, orbiting their parent planets in less predictable paths.\n");
}


void starInput(std::ifstream& input, std::string& newName, std::string& newInfo, std::string& newSpectralTypeStr, double& newMass, double& newRadius, 
    double& newTemperature, char& newSpectralType) {
    std::getline(input, newName, '|');
    std::getline(input, newInfo, '|');
    input >> newMass; input.ignore();
    input >> newRadius; input.ignore();
    input >> newTemperature; input.ignore();
    std::getline(input, newSpectralTypeStr);

    if (newSpectralTypeStr.size() == 1) {
        newSpectralType = newSpectralTypeStr[0];
    }
    else {
        std::cout << "Error: Invalid character data.\n";
        return;
    }
}

void planetoidInput(std::ifstream& input, std::string& newName, std::string& newInfo, double& newMass, double& newOrbitalPeriod, double& newRadius, 
    double& newGravity) {
    std::getline(input, newName, '|');
    std::getline(input, newInfo, '|');
    input >> newMass; input.ignore();
    input >> newOrbitalPeriod; input.ignore();
    input >> newRadius; input.ignore();
    input >> newGravity; input.ignore();
}

void initCelVec()
{
    std::ifstream input;
    input.open("InitialBodies.txt");
    if (input.fail()) {
        std::cout << "File failed to open";
        return;
    }

    // Stars

    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Supergiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Brightgiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Giant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Subgiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Dwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Subdwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    starInput(input, newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Whitedwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));

    // Planets

    double newOrbitalPeriod, newGravity;

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new GasGiant(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new SuperEarth(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new NeptuneLike(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new Terrestrial(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));

    // Satellites

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new MajorMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, celestialVector[10]));

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new IntermediateMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, celestialVector[7]));

    planetoidInput(input, newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new MinorMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, celestialVector[7]));

    input.close();
}

void printCelVec()
{
    for (int i = 0; i < celestialVector.size(); i++) {
        std::cout << celestialVector[i]->getData();
    }
}

bool BMPattern(std::string pattern, std::string text) {
    int posTable[256]{ 0 };

    for (int i = 0; i < pattern.length(); i++) {
        posTable[pattern[i]] = i;
    }

    int i = 0;
    while (i <= text.length() - pattern.length()) {
        int j = pattern.length() - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }
        if (j < 0) {
            return true;
        }
        else {
            i += std::max(1, j - posTable[text[i + pattern.length() - 1]]);
        }
    }
    return false;
}

void searchCelVec(std::string pattern)
{
    int count = 0;
    int entryNum = 1;
    for (int i = 0; i < celestialVector.size(); i++) {
        if (BMPattern(pattern, celestialVector[i]->getData())) {
            std::cout << "Entry " << entryNum << ": \n";
            entryNum++;
            std::cout << celestialVector[i]->getData();
            count++;
        }
    }
    std::cout << "Showing " << count << " results out of " << celestialVector.size() << " entries\n";
}

CelestialBody& findEntry(std::string pattern) 
{
    for (int i = 0; i < celestialVector.size(); i++) {
        if (BMPattern(pattern, celestialVector[i]->getData())) {
            return *celestialVector[i];
        }
    }
}

void sortAlphabetically()
{
    std::sort(celestialVector.begin(), celestialVector.end(), [](CelestialBody* a, CelestialBody* b) { return (a->getName() < b->getName()); });
}

void sortByMass()
{
    std::sort(celestialVector.begin(), celestialVector.end(), [](CelestialBody* a, CelestialBody* b) { return (a->getMass() < b->getMass()); });
}

void programIntro()
{
    std::cout << "Welcome to the Celestial Body Wiki. Please enter the number of the action you want to perform.\n";
    std::cout << "1. Search\n";
    std::cout << "2. Display all entries in alphabetical order\n";
    std::cout << "3. Display all entries by mass\n";
    std::cout << "4. Add new entry\n";
    std::cout << "5. Exit the program\n";
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1:
        search(); break;
    case 2:
        displayAlph(); break;
    case 3:
        displayByMass(); break;
    case 4:
        add(); break;
    case 5:
        return; break;
    default:
        std::cout << "Invalid input, returning to intro\n";
        programIntro(); break;
    }
}

void search()
{
    std::cout << "Enter keyword to search:\n";
    std::string keyword;
    std::cin >> keyword;
    searchCelVec(keyword);
    finalExit();
}

void displayAlph()
{
    sortAlphabetically();
    printCelVec();
    finalExit();
}

void displayByMass()
{
    sortByMass();
    printCelVec();
    finalExit();
}

void add()
{
    std::cout << "What class of Celestial Body would you like to add?\n";
    std::cout << "1. Star\n";
    std::cout << "2. Planet\n";
    std::cout << "3. Satellite\n";
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1:
        addStar(); break;
    case 2:
        addPlanet(); break;
    case 3:
        addSatellite(); break;
    default:
        std::cout << "Invalid input, returning to intro\n";
        programIntro(); break;
    }
}

void addStar()
{
    std::cout << "What type of star would you like to add?\n";
    std::cout << "1. Supergiant\n";
    std::cout << "2. Bright Giant\n";
    std::cout << "3. Giant\n";
    std::cout << "4. Subgiant\n";
    std::cout << "5. Dwarf\n";
    std::cout << "6. Subdwarf\n";
    std::cout << "7. White dwarf\n";
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1:
        addSupergiant(); break;
    case 2:
        addBrightgiant(); break;
    case 3:
        addGiant(); break;
    case 4:
        addSubgiant(); break;
    case 5:
        addDwarf(); break;
    case 6:
        addSubdwarf(); break;
    case 7:
        addWhitedwarf(); break;
    default:
        std::cout << "Invalid input, returning to intro\n";
        programIntro(); break;
    }
}

void addPlanet()
{
    std::cout << "What type of planet would you like to add?\n";
    std::cout << "1. Gas Giant\n";
    std::cout << "2. Super-Earth\n";
    std::cout << "3. Neptune-like\n";
    std::cout << "4. Terrestrial\n";
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1:
        addGasGiant(); break;
    case 2:
        addSuperEarth(); break;
    case 3:
        addNeptuneLike(); break;
    case 4:
        addTerrestrial(); break;
    default:
        std::cout << "Invalid input, returning to intro\n";
        programIntro(); break;
    }
}

void addSatellite()
{
    std::cout << "What type of satellite would you like to add?\n";
    std::cout << "1. Major Moon\n";
    std::cout << "2. Intermediate Moon\n";
    std::cout << "3. Minor Moon\n";
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1:
        addMajorMoon(); break;
    case 2:
        addIntermediateMoon(); break;
    case 3:
        addMinorMoon(); break;
    default:
        std::cout << "Invalid input, returning to intro\n";
        programIntro(); break;
    }
}

void getStarParams(std::string& newName, std::string& newInfo, std::string& newSpectralTypeStr, double& newMass, double& newRadius, double& newTemperature, char& newSpectralType)
{
    std::cout << "Enter name:\n";
    std::cin >> newName;
    std::cout << "\n";
    std::cout << "Enter information:\n";
    std::cin >> newInfo;
    std::cout << "\n";
    std::cout << "Enter spectral type:\n";
    std::cin >> newSpectralTypeStr;
    std::cout << "\n";
    std::cout << "Enter mass:\n";
    std::cin >> newMass;
    std::cout << "\n";
    std::cout << "Enter radius:\n";
    std::cin >> newRadius;
    std::cout << "\n";
    std::cout << "Enter temperature:\n";
    std::cin >> newTemperature;
    std::cout << "\n";
    if (newSpectralTypeStr.size() == 1) {
        newSpectralType = newSpectralTypeStr[0];
    }
    else {
        std::cout << "Error: Invalid character data.\n";
        return;
    }
}

void getPlanetoidParams(std::string& newName, std::string& newInfo, double& newMass, double& newOrbitalPeriod, double& newRadius, double& newGravity)
{
    std::cout << "Enter name:\n";
    std::cin >> newName;
    std::cout << "\n";
    std::cout << "Enter information:\n";
    std::cin >> newInfo;
    std::cout << "\n";
    std::cout << "Enter mass:\n";
    std::cin >> newMass;
    std::cout << "\n";
    std::cout << "Enter orbital period:\n";
    std::cin >> newOrbitalPeriod;
    std::cout << "\n";
    std::cout << "Enter radius:\n";
    std::cin >> newRadius;
    std::cout << "\n";
    std::cout << "Enter gravity:\n";
    std::cin >> newGravity;
    std::cout << "\n";
}

void addSupergiant()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Supergiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addBrightgiant()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Brightgiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addGiant()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Giant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addSubgiant()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Subgiant(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addDwarf()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Dwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addSubdwarf()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Subdwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addWhitedwarf()
{
    std::string newName, newInfo, newSpectralTypeStr;
    double newMass, newRadius, newTemperature;
    char newSpectralType;
    getStarParams(newName, newInfo, newSpectralTypeStr, newMass, newRadius, newTemperature, newSpectralType);
    celestialVector.push_back(new Whitedwarf(newName, newInfo, newMass, newRadius, newTemperature, newSpectralType));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addGasGiant()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new GasGiant(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addSuperEarth()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new SuperEarth(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addNeptuneLike()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new NeptuneLike(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addTerrestrial()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    celestialVector.push_back(new Terrestrial(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addMajorMoon()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    std::string newPlanet;
    std::cout << "Enter planet name:\n";
    std::cin >> newPlanet;
    celestialVector.push_back(new MajorMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, &findEntry(newPlanet)));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addIntermediateMoon()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    std::string newPlanet;
    std::cout << "Enter planet name:\n";
    std::cin >> newPlanet;
    celestialVector.push_back(new IntermediateMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, &findEntry(newPlanet)));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void addMinorMoon()
{
    std::string newName, newInfo;
    double newMass, newOrbitalPeriod, newRadius, newGravity;
    getPlanetoidParams(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity);
    std::string newPlanet;
    std::cout << "Enter planet name:\n";
    std::cin >> newPlanet;
    celestialVector.push_back(new MinorMoon(newName, newInfo, newMass, newOrbitalPeriod, newRadius, newGravity, &findEntry(newPlanet)));
    std::cout << "Entry successfully added!\n";
    finalExit();
}

void finalExit()
{
    std::cout << "Please enter the number of the action you want to perform.\n";
    std::cout << "1. Go back to intro\n";
    std::cout << "Anything to exit\n";
    int answer;
    std::cin >> answer;
    if (answer == 1)
        programIntro();
    else
        return;
}