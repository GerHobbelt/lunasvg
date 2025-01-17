﻿#include "styledelement.h"
#include "parser.h"

namespace lunasvg {

StyledElement::StyledElement(ElementId id)
    : Element(id)
{
}

Paint StyledElement::fill() const
{
    auto& value = find(PropertyId::Fill);
    return Parser::parsePaint(value, this, Color::Black);
}

Paint StyledElement::stroke() const
{
    auto& value = find(PropertyId::Stroke);
    return Parser::parsePaint(value, this, Color::Transparent);
}

Color StyledElement::color() const
{
    auto& value = find(PropertyId::Color);
    return Parser::parseColor(value, this, Color::Black);
}

Color StyledElement::stop_color() const
{
    auto& value = find(PropertyId::Stop_Color);
    return Parser::parseColor(value, this, Color::Black);
}

Color StyledElement::solid_color() const
{
    auto& value = find(PropertyId::Solid_Color);
    return Parser::parseColor(value, this, Color::Black);
}

double StyledElement::opacity() const
{
    auto& value = get(PropertyId::Opacity);
    return Parser::parseNumberPercentage(value, 1.0);
}

double StyledElement::fill_opacity() const
{
    auto& value = find(PropertyId::Fill_Opacity);
    return Parser::parseNumberPercentage(value, 1.0);
}

double StyledElement::stroke_opacity() const
{
    auto& value = find(PropertyId::Stroke_Opacity);
    return Parser::parseNumberPercentage(value, 1.0);
}

double StyledElement::stop_opacity() const
{
    auto& value = find(PropertyId::Stop_Opacity);
    return Parser::parseNumberPercentage(value, 1.0);
}

double StyledElement::solid_opacity() const
{
    auto& value = find(PropertyId::Solid_Opacity);
    return Parser::parseNumberPercentage(value, 1.0);
}

double StyledElement::stroke_miterlimit() const
{
    auto& value = find(PropertyId::Stroke_Miterlimit);
    return Parser::parseNumber(value, 4.0);
}

Length StyledElement::stroke_width() const
{
    auto& value = find(PropertyId::Stroke_Width);
    return Parser::parseLength(value, ForbidNegativeLengths, Length::One);
}

Length StyledElement::stroke_dashoffset() const
{
    auto& value = find(PropertyId::Stroke_Dashoffset);
    return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
}

LengthList StyledElement::stroke_dasharray() const
{
    auto& value = find(PropertyId::Stroke_Dasharray);
    return Parser::parseLengthList(value, ForbidNegativeLengths);
}

WindRule StyledElement::fill_rule() const
{
    auto& value = find(PropertyId::Fill_Rule);
    return Parser::parseWindRule(value);
}

WindRule StyledElement::clip_rule() const
{
    auto& value = find(PropertyId::Clip_Rule);
    return Parser::parseWindRule(value);
}

LineCap StyledElement::stroke_linecap() const
{
    auto& value = find(PropertyId::Stroke_Linecap);
    return Parser::parseLineCap(value);
}

LineJoin StyledElement::stroke_linejoin() const
{
    auto& value = find(PropertyId::Stroke_Linejoin);
    return Parser::parseLineJoin(value);
}

Display StyledElement::display() const
{
    auto& value = get(PropertyId::Display);
    return Parser::parseDisplay(value);
}

Visibility StyledElement::visibility() const
{
    auto& value = find(PropertyId::Visibility);
    return Parser::parseVisibility(value);
}

std::string StyledElement::clip_path() const
{
    auto& value = get(PropertyId::Clip_Path);
    return Parser::parseUrl(value);
}

std::string StyledElement::mask() const
{
    auto& value = get(PropertyId::Mask);
    return Parser::parseUrl(value);
}

std::string StyledElement::marker_start() const
{
    auto& value = find(PropertyId::Marker_Start);
    return Parser::parseUrl(value);
}

std::string StyledElement::marker_mid() const
{
    auto& value = find(PropertyId::Marker_Mid);
    return Parser::parseUrl(value);
}

std::string StyledElement::marker_end() const
{
    auto& value = find(PropertyId::Marker_End);
    return Parser::parseUrl(value);
}

bool StyledElement::isDisplayNone() const
{
    return display() == Display::None;
}

} // namespace lunasvg
