#include "MapGrid.h"

MapGrid::MapGrid()
{
    srand (time(NULL));
	ALLEGRO_BITMAP *bitmap = al_load_bitmap("grass.png");
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength, 0, bitmap);
            if((i == GridHeight - 1)){
                grid[i][j].Setoccupied(2);
            }
        }
    }
    ALLEGRO_BITMAP *arrow = al_load_bitmap("arrow.png");
    int random = rand()%GridWidth;
    grid[0][random] = GridSquare(random*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), 0*SideLength + 10, SideLength, 1, arrow);
    start = &grid[0][random];
	startx = random;
    std::cout << random << " start set" << std::endl;
    random = rand() % GridWidth;
	grid[GridHeight-1][random] = GridSquare(random*SideLength + ScreenWidth / 2 - (SideLength*GridWidth / 2), (GridHeight - 1) * SideLength + 10, SideLength, 4, arrow);
    finish = &grid[GridHeight][random];
    std::cout << random << " finish set" << std::endl;
}

void MapGrid::draw(ALLEGRO_MOUSE_STATE mouse, std::string *title, std::string *description)
{
    hover = NULL;
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            if (grid[i][j].draw(mouse))
            {
                hover = &grid[i][j];
            }
        }
    }
    if(clicked != NULL){
        clicked->draw(mouse);
        *title = clicked->GetName();
        *description = clicked->GetDescription();
    }
    if(hover != NULL){
        hover->draw(mouse);
    }
	Pathfind();
	DrawPath();
}

void MapGrid::SetClicked()
{
    if (clicked != NULL)
    {
        clicked->SetClicked(false);
    }
    clicked = hover;
}

bool MapGrid::Pathfind()
{
	//usage: grid[y][x]
	int y = 0;
	int x = startx;
	//erase the old path
	path.clear();
	//start path with start
	path.push_back(start);
	int tries = 0;
	while (path.back() != finish) {
		if (y <  GridHeight && (grid[y + 1][x].Getoccupied() == 0 || grid[y + 1][x].Getoccupied() == 4)) {
			path.push_back(&grid[y + 1][x]);
			std::cout << "pushed back grid at" << y + 1 << " " << x << std::endl;
			y += 1;
		}
		else if (x > 0 && (grid[y][x - 1].Getoccupied() == 0 || grid[y][x - 1].Getoccupied() == 4)) {
			path.push_back(&grid[y][x - 1]);
			std::cout << "pushed back grid at" << y << " " << x - 1 << std::endl;
			x -= 1;
		}
		else if (x < GridWidth && (grid[y][x + 1].Getoccupied() == 0 || grid[y][x + 1].Getoccupied() == 4)) {
			path.push_back(&grid[y][x + 1]);
			x += 1;
			std::cout << "pushed back grid at" << y << " " << x << std::endl;
		}
		else {
			//could not find path
			return false;
		}
		tries++;
		if (tries == GridHeight * GridWidth) {
			return false;
		}
	}
	

	//we were able to find a path so return true
	return true;
}

void MapGrid::DrawPath()
{
	for (int i = 0; i < path.size(); i++)
	{
		al_draw_filled_circle(path[i]->Getx() + (SideLength/2), path[i]->Gety() + (SideLength /2), SideLength / 2, al_color_name("red"));
	}
}