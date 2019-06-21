/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "gfx/legato/common/legato_utils.h"

#include "gfx/legato/datastructure/legato_list.h"
#include "gfx/legato/widget/legato_widget.h"

#include "gfx/legato/common/legato_rect.h"

leWidget* leUtils_PickFromWidget(const leWidget* parent,
                                 int32_t x,
                                 int32_t y)
{
    const leWidget* child;
    const leWidget* result;
    lePoint pnt;
    uint32_t i;

    pnt.x = x;
    pnt.y = y;

    result = parent;

    for(i = 0; i < parent->children.size; i++)
    {
        child = parent->children.values[i];

        // widget must be enabled and visible
        if(child->enabled == LE_TRUE &&
           child->visible == LE_TRUE &&
           leRectContainsPoint(&child->rect, &pnt) == LE_TRUE)
        {
            result = leUtils_PickFromWidget(child, x - child->rect.x, y - child->rect.y);
        }
    }

    return (leWidget*)result;
}

leWidget* leUtils_Pick(int32_t x, int32_t y)
{
#if 0
    leContext* context = leContext_GetActive();
    leScreen* screen = NULL;
    leLayer* layer = NULL;
    leWidget* widget = NULL;
    lePoint pnt;
    leRect rect;
    int32_t i;

    if(context == NULL)
        return NULL;

    pnt.x = x;
    pnt.y = y;

    // get the active screen
    screen = context->activeScreen;

    rect = leContext_GetScreenRect();

    // screen must contain point
    if(leRectContainsPoint(&rect, &pnt) == LE_FALSE)
        return NULL;

    // find the topmost visible layer that contains the point
    for(i = LE_MAX_LAYERS - 1; i >= 0; i--)
    {
        layer = screen->layers[i];

        // layer must exist and be enabled
        if(layer == NULL || layer->widget.enabled == LE_FALSE)
           continue;

        // layer zero has the lowest z order, always favor higher layers
        if(leRectContainsPoint(&layer->widget.rect, &pnt) == LE_TRUE)
        {
            widget = pickChild((leWidget*)layer,
                                x - layer->widget.rect.x,
                                y - layer->widget.rect.y);
                                
            // no layer qualified
            if(widget != NULL && widget != (leWidget*)layer)
                return widget;
        }
    }
#endif
    // no widget qualified
    return NULL;
}

/*static void pickChildRect(leWidget* parent, leRect rect, leList* list)
{
    leWidget* child;
    leRect childRect;
    uint32_t i;

    for(i = 0; i < parent->children.size; i++)
    {
        child = parent->children.values[i];
        
        childRect = leWidget_RectToScreenSpace(child);
        
        if(leRectIntersects(&rect, &childRect) == LE_TRUE)
            leList_PushBack(list, child);
            
        pickChildRect(child, rect, list);
    }
}*/

/*void leUtils_PickRect(leLayer* layer, leRect rect, leList* list)
{
    leWidget* child;
    leRect childRect;
    uint32_t i;

    if(layer == NULL ||
       layer->widget.enabled == LE_FALSE ||
       list == NULL)
        return;
        
    leList_Clear(list);

    // layer must contain rect
    if(leRectIntersects(&layer->widget.rect, &rect) == LE_FALSE)
        return;
        
    //leRectClip(&rect, &layer->widget.rect, &clippedRect);

    for(i = 0; i < layer->widget.children.size; i++)
    {
        child = layer->widget.children.values[i];
        
        childRect = leWidget_RectToScreenSpace(child);
        
        if(leRectIntersects(&rect, &childRect) == LE_TRUE)
            leList_PushBack(list, child);
            
        pickChildRect(child, rect, list);
    }
}*/

#if 0
leLayer* leUtils_GetLayer(leWidget* widget)
{
    leWidget* parent;
    
    if(widget == NULL)
        return NULL;
   
    if(widget->type == LE_WIDGET_LAYER)
        return (leLayer*)widget;
        
    parent = widget->parent;
    
    while(parent != NULL)
    {
        if(parent->parent == NULL)
            break;
            
        parent = parent->parent;
    }
    
    if(parent == NULL || parent->type != LE_WIDGET_LAYER)
        return NULL;
    
    return (leLayer*)parent;
}

void leUtils_PointToLayerSpace(leWidget* widget, lePoint* pnt)
{
    if(widget == NULL || pnt == NULL)
        return;
        
    while(widget != NULL &&
          widget->type != LE_WIDGET_LAYER)
    {
        pnt->x += widget->rect.x;
        pnt->y += widget->rect.y;
        
        widget = widget->parent;
    }
}
#endif

void leUtils_PointToScreenSpace(leWidget* widget, lePoint* pnt)
{
    if(widget == NULL || pnt == NULL)
        return;
        
    while(widget != NULL)
    {
        pnt->x += widget->rect.x;
        pnt->y += widget->rect.y;

        widget = widget->parent;
    }
}

void leUtils_PointScreenToLocalSpace(leWidget* widget, lePoint* pnt)
{
    leWidget* parent;

    if(widget == NULL || pnt == NULL)
        return;
        
    pnt->x -= widget->rect.x;
    pnt->y -= widget->rect.y;

    parent = widget->parent;

    while(parent != NULL)
    {
        pnt->x -= parent->rect.x;
        pnt->y -= parent->rect.y;

        parent = parent->parent;
    }
}

void leUtils_ClipRectToParent(leWidget* parent, leRect* rect)
{
    leRect result;

    if(parent == NULL || rect == NULL)
        return;

    rect->x += parent->rect.x;
    rect->y += parent->rect.y;

    leRectClip(rect, &parent->rect, &result);

    result.x -= parent->rect.x;
    result.y -= parent->rect.y;

    *rect = result;
}

void leUtils_RectToParentSpace(leWidget* widget, leRect* rect)
{
    if(widget == NULL || rect == NULL || widget->parent == NULL)
        return;

    rect->x += widget->parent->rect.x;
    rect->y += widget->parent->rect.y;
}

void leUtils_RectFromParentSpace(leWidget* widget, leRect* rect)
{
    if(widget == NULL || rect == NULL || widget->parent == NULL)
        return;

    rect->x -= widget->parent->rect.x;
    rect->y -= widget->parent->rect.y;
}

void leUtils_RectToScreenSpace(leWidget* widget, leRect* rect)
{
    if(widget == NULL || rect == NULL)
        return;
        
    while(widget != NULL)
    {
        rect->x += widget->rect.x;
        rect->y += widget->rect.y;

        widget = widget->parent;
    }
}

leBool leUtils_ChildIntersectsParent(const leWidget* parent,
                                     const leWidget* child)
{
    leRect childRect;
    
    if(parent == NULL || child == NULL)
        return LE_FALSE;
        
    childRect = child->rect;
    
    childRect.x += parent->rect.x;
    childRect.y += parent->rect.y;

    return leRectIntersects(&childRect, &parent->rect);
}

leWidget* leUtils_GetNextHighestWidget(const leWidget* wgt)
{
    int32_t idx;
    leWidget *target, *res;
    
    // return first child
    if(wgt->children.size != 0)
        return wgt->children.values[0];
    
    if(wgt->parent == NULL)
        return NULL;
    
    target = wgt->parent;
    
    // return next viable sibling
    while(target != NULL)
    {
        idx = wgt->fn->getIndexOfChild(wgt, target);
    
        res = target->fn->getChildAtIndex(target, ++idx);
        
        if(res != NULL)
            return res;
            
        wgt = target;
        target = wgt->parent;
    }
    
    return NULL;
}

void leUtils_ArrangeRectangle(leRect* sub,
                              leRect obj,
                              leRect bounds,
                              leHAlignment hAlignment,
                              leVAlignment vAlignment,
                              leRelativePosition position,
                              uint8_t leftMargin,
                              uint8_t topMargin,
                              uint8_t rightMargin,
                              uint8_t bottomMargin,
                              uint16_t rectMargin)
{
    sub->x = 0;
    sub->y = 0;
    
    if(hAlignment == LE_HALIGN_LEFT)
    {
        sub->x = bounds.x + leftMargin;
        
        if(obj.width > 0 && position == LE_RELATIVE_POSITION_RIGHTOF)
            sub->x += obj.width + rectMargin;
    }
    else if(hAlignment == LE_HALIGN_CENTER)
    {
        sub->x = bounds.x + (bounds.width / 2) - (sub->width / 2);
        
        if(obj.width > 0)
        {
            if(position == LE_RELATIVE_POSITION_LEFTOF)
                sub->x -= (obj.width / 2) + (rectMargin / 2);
            else if(position == LE_RELATIVE_POSITION_RIGHTOF)
                sub->x += (obj.width / 2) + (rectMargin / 2);
        }
    }
    else
    {
        sub->x = bounds.x + bounds.width - sub->width - rightMargin;
        
        if(obj.width > 0 && position == LE_RELATIVE_POSITION_LEFTOF)
            sub->x -= obj.width + rectMargin;
    }
    
    if(vAlignment == LE_VALIGN_TOP)
    {
        sub->y = bounds.y + topMargin + 1;
        
        if(obj.height > 0)
        {
            if(position == LE_RELATIVE_POSITION_BELOW)
                sub->y += obj.height + rectMargin;
        }
    }
    else if(vAlignment == LE_VALIGN_MIDDLE)
    {
        sub->y = bounds.y + (bounds.height / 2) - (sub->height / 2);
        
        if(obj.height > 0)
        {
            if(position == LE_RELATIVE_POSITION_ABOVE)
                sub->y -= (obj.height / 2) + (rectMargin / 2);
            else if(position == LE_RELATIVE_POSITION_BELOW)
                sub->y += (obj.height / 2) + (rectMargin / 2);
        }
    }
    else
    {
        sub->y = bounds.y + bounds.height - sub->height - bottomMargin ;
        
        if(obj.height > 0 && position == LE_RELATIVE_POSITION_ABOVE)
            sub->y -= obj.height + rectMargin;
    }
}

void leUtils_ArrangeRectangleRelative(leRect* sub,
                                      leRect obj,
                                      leRect bounds,
                                      leHAlignment hAlignment,
                                      leVAlignment vAlignment,
                                      leRelativePosition position,
                                      uint8_t leftMargin,
                                      uint8_t topMargin,
                                      uint8_t rightMargin,
                                      uint8_t bottomMargin,
                                      uint16_t rectMargin)
{
    sub->x = 0;
    sub->y = 0;
    
    if(hAlignment == LE_HALIGN_LEFT)
    {
        sub->x = bounds.x + leftMargin;
        
        if(obj.width > 0)
        {
            if(position == LE_RELATIVE_POSITION_LEFTOF)
                sub->x += obj.width + rectMargin;
            //else
            //    sub->x += (obj.width / 2) - (sub->width / 2);
        }
    }
    else if(hAlignment == LE_HALIGN_CENTER)
    {
        sub->x = bounds.x + (bounds.width / 2) - (sub->width / 2);
        
        if(obj.width > 0)
        {
            if(position == LE_RELATIVE_POSITION_LEFTOF)
                sub->x += (obj.width / 2) + (rectMargin / 2);
            else if(position == LE_RELATIVE_POSITION_RIGHTOF)
                sub->x -= (obj.width / 2) + (rectMargin / 2);
        }
    }
    else
    {
        sub->x = bounds.x + bounds.width - sub->width - rightMargin;
        
        if(obj.width > 0)
        {   
            if(position == LE_RELATIVE_POSITION_RIGHTOF)
                sub->x -= obj.width + rectMargin;
            //else
            //    sub->x -= (obj.width / 2) - (sub->width / 2);
        }
    }
    
    if(vAlignment == LE_VALIGN_TOP)
    {
        sub->y = bounds.y + topMargin + 1;
        
        if(obj.height > 0 && position != LE_RELATIVE_POSITION_BELOW)
        {
            if(position == LE_RELATIVE_POSITION_ABOVE)
                sub->y += obj.height + rectMargin;
            else
                sub->y += (obj.height / 2) - (sub->height / 2);
            
            if (sub->y < (bounds.y + topMargin + 1))
                sub->y = bounds.y + topMargin + 1;
        }
    }
    else if(vAlignment == LE_VALIGN_MIDDLE)
    {
        sub->y = bounds.y + (bounds.height / 2) - (sub->height / 2);
        
        if(obj.height > 0)
        {
            if(position == LE_RELATIVE_POSITION_ABOVE)
                sub->y += (obj.height / 2) + (rectMargin / 2);
            else if(position == LE_RELATIVE_POSITION_BELOW)
                sub->y -= (obj.height / 2) + (rectMargin / 2);
        }
    }
    else
    {
        sub->y = bounds.y + bounds.height - sub->height - bottomMargin;
        
        if(obj.height > 0 && position != LE_RELATIVE_POSITION_ABOVE)
        {
            if(position == LE_RELATIVE_POSITION_BELOW)
                sub->y -= obj.height + rectMargin;
            else
                sub->y -= (obj.height / 2) - (sub->height / 2);
            
            if ((sub->y + sub->height) > (bounds.y + bounds.height - bottomMargin))
                sub->y = bounds.y + bounds.height - sub->height - bottomMargin;
        }
    }
}

leBool _occlusionCullTestAscending(leWidget* widget, leRect* bounds)
{
    uint32_t i, idx;
    leWidget *parent, *child;
    leRect childRect;
    
    // root node of tree, can't possibly occlude
    if(widget->parent == NULL)
        return LE_FALSE;
        
    parent = widget->parent;
        
    bounds->x += parent->rect.x;
    bounds->y += parent->rect.y;
    
    idx = leArray_Find(&parent->children, widget);
    
    if(idx < parent->children.size - 1)
    {    
        idx += 1;
        
        // test all rightside siblings, leftside can't occlude
        for(i = idx; i < parent->children.size; i++)
        {
            child = parent->children.values[i];
            
            childRect = child->rect;
            
            // move child rect into parent space
            //childRect.x += widget->rect.x;
            //childRect.y += widget->rect.y;
            
            if(leRectContainsRect(&childRect, bounds) == LE_TRUE)
                return LE_TRUE;
        }
    }
    
    return _occlusionCullTestAscending(parent, bounds);
}

leBool leUtils_OcclusionCullTest(leWidget* widget)
{
    uint32_t i;
    leWidget* child;
    leRect childRect;
    
    if(widget == NULL)
        return LE_FALSE;
    
    // test children first
    for(i = 0; i < widget->children.size; i++)
    {
        child = widget->children.values[i];
        
        childRect = child->rect;
        
        // move child rect into parent space
        //childRect.x += widget->rect.x;
        //childRect.y += widget->rect.y;
        
        if(leRectContainsRect(&childRect, &widget->rect) == LE_TRUE)
            return LE_TRUE;
    }
    
    // test rightmost ancestors
    childRect = widget->rect;
    
    return _occlusionCullTestAscending(widget, &childRect);
}

void leUtils_ListOcclusionCullTest(leList* list, leRect rect)
{
    uint32_t i, j;
    leWidget *widget, *higherWidget;
    leRect widgetRect;//, lclippedRect, rclippedRect;
    leList cullList;
    leBool cull;
    
    leList_Create(&cullList);
    leList_Copy(&cullList, list);
    leList_Clear(list);
    
    if(cullList.size == 0)
        return;

    for(i = 0; i <= cullList.size - 1; i++)
    {
        cull = LE_FALSE;
        
        widget = (leWidget*)leList_Get(&cullList, i);
        
        // topmost widget is always a pass
        if(i == cullList.size - 1)
        {
            leList_PushBack(list, widget);
        
            continue;
        }
        
        widgetRect = widget->fn->rectToScreen(widget);
        
        //leRectClip(&widgetRect, &rect, &lclippedRect);
        
        for(j = i + 1; j < cullList.size; j++)
        {
            higherWidget = (leWidget*)leList_Get(&cullList, j);
            
            //leRectClip(&higherWidget->rect, &widgetRect, &rclippedRect);
            
            if(leRectContainsRect(&higherWidget->rect, &widgetRect) == LE_TRUE &&
               higherWidget->fn->isOpaque(higherWidget) == LE_TRUE)
            {
                cull = LE_TRUE;
                
                break;
            }
        }
        
        if(cull == LE_FALSE)
            leList_PushBack(list, widget);
    }
    
    leList_Clear(&cullList);
}

leBool leUtils_WidgetIsOccluded(const leWidget* wgt, const leRect* rect)
{
    leWidget* target;
    leRect targetRect;
    
    if(wgt->fn->getCumulativeAlphaEnabled(wgt) == LE_TRUE)
        return LE_FALSE;
    
    target = leUtils_GetNextHighestWidget(wgt);
    
    while(target != NULL)
    {
        targetRect = target->fn->rectToScreen(target);
        
        if(target->visible == LE_TRUE &&
           target->alphaEnabled == LE_FALSE &&
           target->backgroundType != LE_WIDGET_BACKGROUND_NONE &&
           leRectContainsRect(&targetRect, rect) == LE_TRUE)
            return LE_TRUE;
            
        target = leUtils_GetNextHighestWidget(target);
    }
    
    return LE_FALSE;
}
