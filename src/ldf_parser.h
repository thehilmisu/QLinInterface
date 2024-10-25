#ifndef LDF_PARSER_H
#define LDF_PARSER_H

#include <string>
#include <map>
#include <vector>
#include <cstdint>

struct Signal {
    std::string name;
    uint8_t size;
    std::string publisher;
    std::string subscriber;
};

struct Frame {
    std::string name;
    uint8_t id;
    std::string sender;
    uint8_t length;
    std::vector<std::string> signalList;
};

class LdfParser
{
public:
    LdfParser(const std::string &ldfFilePath);
    bool parse();

    std::map<std::string, Signal> getSignals() const;
    std::map<std::string, Frame> getFrames() const;

private:
    void parseNodes(const std::string &line);
    void parseSignals(const std::string &line);
    void parseFrames(const std::string &line);

    std::string ldfFilePath;
    std::map<std::string, Signal> signalMap;
    std::map<std::string, Frame> frames;
};

#endif // LDF_PARSER_H

