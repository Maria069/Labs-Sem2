#pragma once

#include "planet/planet.h"
#include "article/article.h"

#include <cstddef>

namespace Application {
void ChoseEditPlanetPlace(Planet* list, int size, char *objName);
void ChoseEdiArticlePlace(Article* list, int size, char *objName);
void StartSolarSystem();
void StartArticle();
void StartApp();
} // namespace Application