#include "ldf_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

LdfParser::LdfParser(const std::string &ldfFilePath) : ldfFilePath(ldfFilePath) {}

bool LdfParser::parse()
{
    std::ifstream file(ldfFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open LDF file: " << ldfFilePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Nodes {") != std::string::npos) {
            parseNodes(line);
        } else if (line.find("Signals {") != std::string::npos) {
            while (std::getline(file, line) && line.find("}") == std::string::npos) {
                parseSignals(line);
            }
        } else if (line.find("Frames {") != std::string::npos) {
            while (std::getline(file, line) && line.find("}") == std::string::npos) {
                parseFrames(line);
            }
        }
    }

    file.close();
    return true;
}

void LdfParser::parseNodes(const std::string &line)
{
    // Parsing Nodes (not fully implemented)
    std::istringstream iss(line);
    std::string nodeType, nodeName;
    char colon;

    iss >> nodeType;
    if (nodeType == "Master" || nodeType == "Slaves") {
        // Parse node names separated by commas
        while (iss >> nodeName) {
            // Remove trailing commas if present
            if (nodeName.back() == ',') {
                nodeName.pop_back();
            }
            std::cout << "Parsed Node: " << nodeType << " - " << nodeName << std::endl;
        }
    }
}

void LdfParser::parseSignals(const std::string &line)
{
    std::istringstream iss(line);
    Signal signal;
    char colon;
    iss >> signal.name >> colon >> signal.size >> colon;
    iss >> signal.publisher >> colon >> signal.subscriber;
    signalMap[signal.name] = signal;
    std::cout << "Parsed Signal: " << signal.name << " Size: " << static_cast<int>(signal.size) << std::endl;
}

void LdfParser::parseFrames(const std::string &line)
{
    std::istringstream iss(line);
    Frame frame;
    char colon;
    iss >> frame.name >> colon >> frame.id >> colon;
    iss >> frame.sender >> colon >> frame.length;
    frames[frame.name] = frame;
    std::cout << "Parsed Frame: " << frame.name << " ID: " << static_cast<int>(frame.id) << " Length: " << static_cast<int>(frame.length) << std::endl;
}

std::map<std::string, Signal> LdfParser::getSignals() const
{
    return signalMap;
}

std::map<std::string, Frame> LdfParser::getFrames() const
{
    return frames;
}

