#ifndef VELO_DEBUG_HPP
#define VELO_DEBUG_HPP

#define VELOMESSAGE(message) veloPushMessage(MessageType::DEFAULT, #message, __FILE__, __LINE__)

#include <string>
#include <ostream>

enum class MessageType
{
    DEFAULT = 0,
    CHANGE,
    
};

struct Message
{
    MessageType type;
    std::string text;
    std::string file;
    int line;
};

static Message messages[100];
static size_t messageIndex = 0;

void veloPushMessage(MessageType type, const char* text, const char* file, int line)
{
    Message message;
    message.type = type;
    message.text = text;
    message.file = file;
    message.line = line;
    ::messages[messageIndex++] = message;
}

void veloPrintMessages(std::ostream& os, bool simplified = true)
{
    if (simplified)
    {
        for (size_t i = 0; i < messageIndex; i++)
        {
            os << "Message: \"" << messages[i].text << "\" at line: " << messages[i].line << std::endl;
        }
        return;
    }
    for (size_t i = 0; i < messageIndex; i++)
    {
        os << "Message: \"" << messages[i].text << "\" in file: " << messages[i].file << " at line: " << messages[i].line << std::endl;
    }
}

#endif // VELO_DEBUG_HPP