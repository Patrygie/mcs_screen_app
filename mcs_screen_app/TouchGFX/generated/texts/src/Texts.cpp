/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x4c, 0x20, 0x4d, 0x6f, 0x74, 0x6f, 0x72, 0x20, 0x44, 0x72, 0x69, 0x76, 0x65, 0x72, 0x0, // @0 "L Motor Driver"
    0x4d, 0x43, 0x53, 0x5f, 0x66, 0x72, 0x6f, 0x6e, 0x74, 0x5f, 0x73, 0x65, 0x6e, 0x73, 0x0, // @15 "MCS_front_sens"
    0x52, 0x20, 0x4d, 0x6f, 0x74, 0x6f, 0x72, 0x20, 0x44, 0x72, 0x69, 0x76, 0x65, 0x72, 0x0, // @30 "R Motor Driver"
    0x4d, 0x53, 0x43, 0x5f, 0x72, 0x65, 0x61, 0x72, 0x5f, 0x65, 0x63, 0x0, // @45 "MSC_rear_ec"
    0x43, 0x41, 0x4e, 0x20, 0x53, 0x54, 0x41, 0x54, 0x55, 0x53, 0x0, // @57 "CAN STATUS"
    0x2, 0x25, 0x0, // @68 "<>%"
    0x4d, 0x43, 0x53, 0x5f, 0x6d, 0x61, 0x69, 0x6e, 0x0, // @71 "MCS_main"
    0x4d, 0x43, 0x53, 0x5f, 0x73, 0x63, 0x72, 0x6e, 0x0, // @80 "MCS_scrn"
    0x2, 0x0, // @89 "<>"
    0x4d, 0x43, 0x53, 0x5f, 0x68, 0x76, 0x0, // @91 "MCS_hv"
    0x4d, 0x43, 0x53, 0x5f, 0x6c, 0x76, 0x0, // @98 "MCS_lv"
    0x49, 0x4e, 0x56, 0x20, 0x4c, 0x0, // @105 "INV L"
    0x49, 0x4e, 0x56, 0x20, 0x52, 0x0, // @111 "INV R"
    0x4d, 0x4f, 0x54, 0x20, 0x4c, 0x0, // @117 "MOT L"
    0x4d, 0x4f, 0x54, 0x20, 0x52, 0x0, // @123 "MOT R"
    0x44, 0x49, 0x46, 0x46, 0x0, // @129 "DIFF"
    0x54, 0x53, 0x41, 0x43, 0x0, // @134 "TSAC"
    0x30, 0x30, 0x25, 0x0, // @139 "00%"
    0x41, 0x4d, 0x53, 0x0, // @143 "AMS"
    0x42, 0x41, 0x54, 0x0, // @147 "BAT"
    0x45, 0x52, 0x52, 0x0, // @151 "ERR"
    0x4c, 0x4f, 0x57, 0x0, // @155 "LOW"
    0x4d, 0x41, 0x50, 0x0, // @159 "MAP"
    0x50, 0x32, 0x44, 0x0, // @163 "P2D"
    0x30, 0x30, 0x0, // @167 "00"
    0x54, 0x43, 0x0, // @170 "TC"
    0x54, 0x53, 0x0, // @173 "TS"
    0x2d, 0x0 // @176 "-"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
