#include "CApp.h"
#include "CDraw.h"

void CApp::OnChangePenTraectory()
{
    // Решаем траекторию движения пера
    traectory = CDraw::GetAllPointsBrezenham(Pen.x, Pen.y, Dest.x, Dest.y);
    traectory_it = traectory.begin();
    traectory_it++;
    Dest = *std::prev(traectory.end());
}
