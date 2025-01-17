#include "element.h"
#include "parser.h"
#include "svgelement.h"

namespace lunasvg {

static const std::string KEmptyString;

Element::Element(ElementId id)
    : id(id)
{
}

void Element::insert(PropertyId id, const std::string& value)
{
    properties.emplace(id, value);
}

void Element::set(PropertyId id, const std::string& value)
{
    properties[id] = value;
}

const std::string& Element::get(PropertyId id) const
{
    auto it = properties.find(id);
    return it == properties.end() ? KEmptyString : it->second;
}

const std::string& Element::find(PropertyId id) const
{
    auto& value = get(id);
    if(value.empty() || value.compare("inherit") == 0)
        return parent ? parent->find(id) : KEmptyString;
    return value;
}

bool Element::has(PropertyId id) const
{
    auto it = properties.find(id);
    return it != properties.end();
}

Node* Element::addChild(std::unique_ptr<Node> child)
{
    child->parent = this;
    children.push_back(std::move(child));
    return &*children.back();
}

Rect Element::nearestViewBox() const
{
    if(parent == nullptr)
        return Rect{0, 0, 512, 512};

    if(parent->id == ElementId::Svg)
    {
        auto element = static_cast<SVGElement*>(parent);
        if(element->has(PropertyId::ViewBox))
            return element->viewBox();

        LengthContext lengthContext(this);
        auto _x = lengthContext.valueForLength(element->x(), LengthMode::Width);
        auto _y = lengthContext.valueForLength(element->y(), LengthMode::Height);
        auto _w = lengthContext.valueForLength(element->width(), LengthMode::Width);
        auto _h = lengthContext.valueForLength(element->height(), LengthMode::Height);
        return Rect{_x, _y, _w, _h};
    }

    return parent->nearestViewBox();
}

void Element::layoutChildren(LayoutContext* context, LayoutContainer* current) const
{
    for(auto& child : children)
        child->layout(context, current);
}

void Node::layout(LayoutContext*, LayoutContainer*) const
{
}

std::unique_ptr<Node> TextNode::clone() const
{
    auto node = std::make_unique<TextNode>();
    node->text = text;
    return std::move(node);
}

} // namespace lunasvg
