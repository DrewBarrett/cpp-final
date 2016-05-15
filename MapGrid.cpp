#include "MapGrid.h"

MapGrid::MapGrid()
{
    srand (time(NULL));
	ALLEGRO_BITMAP *bitmap = al_load_bitmap("grass.png");
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength, 0, bitmap,j,i);
            if((i == GridHeight - 1)){
                grid[i][j].Setoccupied(2);
            }
        }
    }
    ALLEGRO_BITMAP *arrow = al_load_bitmap("arrow.png");
    int random = rand()%GridWidth;
    grid[0][random] = GridSquare(random*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), 0*SideLength + 10, SideLength, 1, arrow,random,0);
    start = &grid[0][random];//broken
	startx = random;
    std::cout << random << " start set" << std::endl;
    random = rand() % GridWidth;
	grid[GridHeight-1][random] = GridSquare(random*SideLength + ScreenWidth / 2 - (SideLength*GridWidth / 2), (GridHeight - 1) * SideLength + 10, SideLength, 4, arrow,random,GridHeight-1);
    finish = &grid[GridHeight][random];//broken
	finishx = random;
    std::cout << random << " finish set" << std::endl;
	//Pathfind();
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
	////usage: grid[y][x]
	//int y = 0;
	//int x = startx;
	////erase the old path
	//path.clear();
	////start path with start
	//path.push_back(start);
	//int tries = 0;
	//while (path.back() != finish) {
	//	if (y <  GridHeight && (grid[y + 1][x].Getoccupied() == 0 || grid[y + 1][x].Getoccupied() == 4)) {
	//		path.push_back(&grid[y + 1][x]);
	//		std::cout << "pushed back grid at" << y + 1 << " " << x << std::endl;
	//		y += 1;
	//	}
	//	else if (x > 0 && (grid[y][x - 1].Getoccupied() == 0 || grid[y][x - 1].Getoccupied() == 4)) {
	//		path.push_back(&grid[y][x - 1]);
	//		std::cout << "pushed back grid at" << y << " " << x - 1 << std::endl;
	//		x -= 1;
	//	}
	//	else if (x < GridWidth && (grid[y][x + 1].Getoccupied() == 0 || grid[y][x + 1].Getoccupied() == 4)) {
	//		path.push_back(&grid[y][x + 1]);
	//		x += 1;
	//		std::cout << "pushed back grid at" << y << " " << x << std::endl;
	//	}
	//	else {
	//		//could not find path
	//		return false;
	//	}
	//	tries++;
	//	if (tries == GridHeight * GridWidth) {
	//		//we hit an loop in the pathfinding
	//		std::cout << "ERROR: Pathfinding loop" << std::endl;
	//		return false;
	//	}
	//}
	//

	////we were able to find a path so return true
	//return true;

	//https://en.wikipedia.org/wiki/A*_search_algorithm#Pseudocode
	std::vector<GridSquare*> closedSet;//nodes that have allready been checked
	std::vector<GridSquare*> openSet;//nodes that need to be evaluated

	//reset start and finish because they dont work otherwise?
	start = &grid[0][startx];
	finish = &grid[GridHeight - 1][finishx];

	openSet.push_back(start);
	//gScore is the cost of going from start to current node
	//The cost of going from start to start is 0
	start->SetGScore(0);
	//fScore is the cost of getting to the end node from the start node by going through the current node
	//As long as this is consistent it doesnt matter if it is correct
	start->SetFScore(EstimateCostToFinish(start->GetGridX(), start->GetGridY()));

	while (openSet.size() > 0) 
	{
		GridSquare *current = openSet[0];
		int CurrentPos = 0;
		//set the current square to the node in openSet with the lowest fScore
		for (int i = 0; i < openSet.size(); i++)
		{
			if (openSet[i]->GetFScore() > current->GetFScore())
			{
				current = openSet[i];
				CurrentPos = i;
			}
		}
		if (current == finish) 
		{
			
			int cx = current->GetGridX();
			int cy = current->GetGridY();
			std::cout << current->Getx() << " current x " << cx << cy << std::endl;
			std::cout << current->GetParent()->Getx() << " current x " << current->GetParent()->GetGridX() << std::endl;
			//path.clear();
			pathx.clear();
			pathy.clear();
			//path.push_back(&grid[current->GetGridY()][current->GetGridX()]);
			pathx.push_back(cx);
			pathy.push_back(cy);
			//ReconstructPath();
			std::cout << "Found path!" << std::endl;
			return true;
		}
		openSet.erase(openSet.begin()+CurrentPos);
		closedSet.push_back(current);
		//generate vector of neighbors
		std::vector<GridSquare*> neighbors;
		int gridY = current->GetGridY();
		int gridX = current->GetGridX();
		if (gridY > 0) 
		{
			//add above square to neighbors
			neighbors.push_back(&grid[gridY-1][gridX]);
			std::cout << "pushed back neigbor at " << gridY - 1 << " " << gridX << std::endl;
		}
		if (gridX > 0)
		{
			//add left square to neighbors
			neighbors.push_back(&grid[gridY][gridX-1]);
			std::cout << "pushed back neigbor at " << gridY << " " << gridX - 1 << std::endl;
		}
		if (gridX < GridWidth)
		{
			//add right square to neighbors
			neighbors.push_back(&grid[gridY][gridX+1]);
			std::cout << "pushed back neigbor at " << gridY << " " << gridX + 1 << std::endl;
		}
		if (gridY < GridHeight - 1)
		{
			//add below square to neighbors
			neighbors.push_back(&grid[gridY + 1][gridX]);
			std::cout << "pushed back neigbor at " << gridY + 1 << " " << gridX << std::endl;
		}
		int bestNeighborGScore = NULL;
		for (int i = 0; i < neighbors.size(); i++)
		{
			//check to make sure we havent checked this square already
			bool checked = false;
			for (int j = 0; j < closedSet.size(); j++)
			{
				if (neighbors[i] == closedSet[j])
				{
					checked = true;
				}
			}
			if (checked)
				continue;//tells neighbors for loop to go to next neighbor
			//find the distance to start to this neighbor
			int neighborGScore = current->GetGScore() + 1;
			bool open = false;
			for (int j = 0; j < openSet.size(); j++)
			{
				if (neighbors[i] == openSet[j])
				{
					open = true;
				}
			}
			if (!open)
			{
				//add this to open nodes
				openSet.push_back(neighbors[i]);
			}
			else if (bestNeighborGScore != NULL && neighborGScore >= bestNeighborGScore)
			{
				//not a better path
				continue;
			}

			//this is currently the best path!
			try
			{
				neighbors[i]->SetParent(current);
				neighbors[i]->SetGScore(neighborGScore);
				bestNeighborGScore = neighborGScore;
				neighbors[i]->SetFScore(neighborGScore + EstimateCostToFinish(neighbors[i]->GetGridX(), neighbors[i]->GetGridY()));
			}
			catch (const std::exception&)
			{
				std::cout << "ERROR";
			}

		}
	}
	//failed to find path
	std::cout << "failed to find path!" << std::endl;
	return false;
}

void MapGrid::ReconstructPath()
{
	finish = &grid[GridHeight - 1][finishx];
	path.clear();
	std::cout << "reconstructed path!" << std::endl;
	path.push_back(finish);
	path.push_back(finish->GetParent());
}

void MapGrid::DrawPath()
{
	for (int i = 0; i < pathx.size(); i++)
	{
		//std::cout << grid[GridHeight - 1][finishx].GetGridX() << " " << grid[GridHeight - 1][finishx].Getx() << std::endl;
		//std::cout << grid[GridHeight - 1][finishx].GetParent()->GetGridX() << " " << grid[GridHeight - 1][finishx].GetParent()->Getx() << std::endl;
		//std::cout << "drawing path circle" << path[i]->Getx() << std::endl;
		al_draw_filled_circle(grid[pathy[i]][pathx[i]].Getx() + (SideLength/2), grid[pathy[i]][pathx[i]].Gety() + (SideLength /2), SideLength / 4, al_color_name("red"));
	}
}

int MapGrid::EstimateCostToFinish(int x, int y) 
{
	std::cout << x << " " << y << std::endl;
	std::cout << (std::abs(x - finish->GetGridX()) + std::abs(y - finish->GetGridY())) << std::endl;
	return (std::abs(x - finish->GetGridX()) + std::abs(y - finish->GetGridY()));
}