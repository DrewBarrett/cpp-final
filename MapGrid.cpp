#include "MapGrid.h"

MapGrid::MapGrid()
{
	//printf("empty map grid created\n");
}

MapGrid::MapGrid(std::vector<Enemy>* memes)
{
	enemies = memes;
    srand (time(NULL));
	ALLEGRO_BITMAP *bitmap = al_load_bitmap("grass.png");
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength, 0, bitmap,j,i, enemies, shootsound);
            if((i == GridHeight - 1)){
                grid[i][j].Setoccupied(2);
            }
        }
    }
    ALLEGRO_BITMAP *arrow = al_load_bitmap("arrow.png");
    int random = rand()%GridWidth;
    grid[0][random] = GridSquare(random*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), 0*SideLength + 10, SideLength, 1, arrow,random,0, enemies, shootsound);
    start = &grid[0][random];//broken
	startx = random;
    std::cout << random << " start set" << std::endl;
    random = rand() % GridWidth;
	grid[GridHeight-1][random] = GridSquare(random*SideLength + ScreenWidth / 2 - (SideLength*GridWidth / 2), (GridHeight - 1) * SideLength + 10, SideLength, 4, arrow,random,GridHeight-1, enemies,shootsound);
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
		if (!clicked->IsParentNull()) {
			std::string newDesc = "";
			std::stringstream sstm;
			sstm << "DEBUG: Parent X: " << clicked->GetParentX() << " Parent Y: " << clicked->GetParentY() << " My fScore: " << clicked->GetFScore() << " my gScore: " << clicked->GetGScore();
			newDesc = sstm.str();
			*description = newDesc;
		}

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

//void MapGrid::setEnemies()
//{
//
//}

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

	std::cout << "Starting pathfind..." << std::endl;
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
			if (openSet[i]->GetFScore() < current->GetFScore())
			{
				current = openSet[i];
				CurrentPos = i;
			}
		}
		if (current == finish)
		{

			//int cx = current->GetGridX();
			//int cy = current->GetGridY();
			int cx = finishx;
			int cy = GridHeight - 1;

			//path.clear();
			try
			{
				//std::cout << current->Getx() << " current x " << cx << cy << std::endl;
				//std::cout << current->GetParent()->Getx() << " current x " << current->GetParent()->GetGridX() << std::endl;
				pathx.clear();
				pathy.clear();
				//remove every grid from path
				for (int i = 0; i < GridHeight; i++)
				{
					for (int j = 0; j < GridWidth; j++)
					{
						grid[i][j].SetOnPath(false);
					}
				}
				pathx.push_back(cx);
				pathy.push_back(cy);
				//std::cout << "pushed back final point at " << cx << " " << cy << std::endl;
				//while (!grid[cy][cx].IsParentNull()) {
				//	//current = current->GetParent();
				//	cx = grid[cy][cx].GetParentX();
				//	cy = grid[cy][cx].GetParentY();
				//	//std::cout << grid[cy][cx].GetParentX() << " " << grid[cy][cx].GetParentY() << std::endl;
				//	std::cout << "parent of last node is " << cx << " " << cy << std::endl;
				//	pathx.push_back(cx);
				//	pathy.push_back(cy);
				//}
				while (cx != startx || cy != 0) {
					grid[cy][cx].SetOnPath(true);
					int newcx = grid[cy][cx].GetParentX();
					int newcy = grid[cy][cx].GetParentY();
					//std::cout << grid[cy][cx].GetParentX() << " " << grid[cy][cx].GetParentY() << std::endl;
					//std::cout << "last node was" << cx << " " << cy << " and its parent is " << newcx << " " << newcy<< std::endl;
					cx = newcx;
					cy = newcy;
					pathx.push_back(cx);
					pathy.push_back(cy);
				}
				//for (int i = 0; i < pathx.size(); i++)
				//{
					//std::cout << pathx[i] << " :x y: " << pathy[i] << std::endl;
				//}
			}
			catch (...)
			{
				std::cout << "ERROR";
			}
			//path.push_back(&grid[current->GetGridY()][current->GetGridX()]);

			//ReconstructPath();
			std::cout << "Found path!" << std::endl;
			return true;
		}
		openSet.erase(openSet.begin()+CurrentPos);
		closedSet.push_back(current);
		//generate vector of neighbors
		//std::vector<GridSquare*> neighbors;
		std::vector<int> neighborX;
		std::vector<int> neighborY;
		int gridY = current->GetGridY();
		int gridX = current->GetGridX();
		if (gridY > 0)
		{
			//add above square to neighbors
			if (grid[gridY - 1][gridX].Getoccupied() == 0 || grid[gridY - 1][gridX].Getoccupied() == 4)
			{
				neighborX.push_back(grid[gridY - 1][gridX].GetGridX());
				neighborY.push_back(grid[gridY - 1][gridX].GetGridY());
				//std::cout << "the approaching neighbor reported its xy as: " << grid[gridY - 1][gridX].GetGridX() << " " << grid[gridY - 1][gridX].GetGridY() << std::endl;
				//std::cout << "pushed back neigbor at " << gridX << " " << gridY - 1 << std::endl;
			}
		}
		if (gridX > 0)
		{
			//add left square to neighbors
			if (grid[gridY][gridX - 1].Getoccupied() == 0 || grid[gridY][gridX - 1].Getoccupied() == 4)
			{
				neighborX.push_back(grid[gridY][gridX - 1].GetGridX());
				neighborY.push_back(grid[gridY][gridX - 1].GetGridY());
				//std::cout << "pushed back neigbor at " << gridX - 1  << " " <<  gridY << std::endl;
			}
		}
		if (gridX < GridWidth - 1)
		{
			//add right square to neighbors
			if (grid[gridY][gridX + 1].Getoccupied() == 0 || grid[gridY][gridX + 1].Getoccupied() == 4)
			{
				neighborX.push_back(grid[gridY][gridX + 1].GetGridX());
				neighborY.push_back(grid[gridY][gridX + 1].GetGridY());
				//std::cout << "pushed back neigbor at " << gridX + 1 << " " << gridY << std::endl;
			}
		}
		if (gridY < GridHeight - 1)
		{
			//add below square to neighbors
			//neighbors.push_back(&grid[gridY + 1][gridX]);
			if (grid[gridY + 1][gridX].Getoccupied() == 0 || grid[gridY + 1][gridX].Getoccupied() == 4)
			{
				neighborX.push_back(grid[gridY + 1][gridX].GetGridX());
				neighborY.push_back(grid[gridY + 1][gridX].GetGridY());
				//std::cout << "pushed back neigbor at " << gridX << " " << gridY + 1 << std::endl;
			}
		}
		int bestNeighborGScore = NULL;
		for (int i = 0; i < neighborX.size(); i++)
		{
			//check to make sure we havent checked this square already
			bool checked = false;
			for (int j = 0; j < closedSet.size(); j++)
			{
				if (neighborX[i] == closedSet[j]->GetGridX() && neighborY[i] == closedSet[j]->GetGridY())
				{
					//std::cout << "the neighbor at " << neighborX[i] << " " << neighborY[i] << " has been checked already... on to the next one!" << std::endl;
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
				if (neighborX[i] == openSet[j]->GetGridX() && neighborY[i] == openSet[j]->GetGridY())
				{
					//std::cout << "the neigbor at " << neighborX[i] << " " << neighborY[i] << "Is in the open set at " << j << " " << openSet[j]->GetGridX() << " " << openSet[j]->GetGridY() << std::endl;
					open = true;
				}
			}
			if (!open)
			{
				//add this to open nodes
				//std::cout << "adding the neigbor at " << neighborX[i] << " " << neighborY[i] << " to the open set";
				openSet.push_back(&grid[neighborY[i]][neighborX[i]]);
			}
			else if (bestNeighborGScore != NULL && neighborGScore >= bestNeighborGScore)
			{
				//not a better path
				//std::cout << "This is not a better path at " << neighborX[i] << " " << neighborY[i] << std::endl;
				continue;
			}

			//this is currently the best path!
			try
			{
				//grid[neighborY[i]][neighborX[i]].SetParent(current);
				grid[neighborY[i]][neighborX[i]].SetParentX(current->GetGridX());
				grid[neighborY[i]][neighborX[i]].SetParentY(current->GetGridY());
				//std::cout << "set parent xy for " << neighborX[i] << " " << neighborY[i] << "to " << current->GetGridX() << " " << current->GetGridY() << std::endl;
				//std::cout << "confirming last statement for " << neighborX[i] << " " << neighborY[i] << " parrent x and y are: " << grid[neighborY[i]][neighborX[i]].GetParentX() << " " << grid[neighborY[i]][neighborX[i]].GetParentY() << std::endl;
				grid[neighborY[i]][neighborX[i]].SetGScore(neighborGScore);
				bestNeighborGScore = neighborGScore;
				grid[neighborY[i]][neighborX[i]].SetFScore(neighborGScore + EstimateCostToFinish(neighborX[i], neighborY[i]));
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

void MapGrid::GetPath(std::vector<int> *x, std::vector<int> *y)
{
    for (int i = 0; i < pathx.size(); i++)
    {
        x->push_back(grid[pathy[i]][pathx[i]].Getx());
        y->push_back(grid[pathy[i]][pathx[i]].Gety());
    }

}

void MapGrid::ReconstructPath()
{
	//finish = &grid[GridHeight - 1][finishx];
	//path.clear();
	//std::cout << "reconstructed path!" << std::endl;
	//path.push_back(finish);
	//path.push_back(finish->GetParent());
}

void MapGrid::DrawPath()
{
	for (int i = 0; i < pathx.size(); i++)
	{
		//std::cout << grid[GridHeight - 1][finishx].GetGridX() << " " << grid[GridHeight - 1][finishx].Getx() << std::endl;
		//std::cout << grid[GridHeight - 1][finishx].GetParent()->GetGridX() << " " << grid[GridHeight - 1][finishx].GetParent()->Getx() << std::endl;
		//std::cout << "drawing path circle" << std::endl;
		//std::cout << pathx.size() << " " << pathy.size() << std::endl;
		//std::cout << pathy.at(i) << std::endl;
		//std::cout << pathx.at(i) << std::endl;
		//std::cout << grid[pathy[i]][pathx[i]].Getx() << std::endl;
		al_draw_filled_circle(grid[pathy[i]][pathx[i]].Getx() + (SideLength/2), grid[pathy[i]][pathx[i]].Gety() + (SideLength /2), SideLength / 4, al_color_name("red"));
		//std::cout << "drawed path circle" << std::endl;
	}
}

int MapGrid::EstimateCostToFinish(int x, int y)
{
	//std::cout << x << " " << y << std::endl;
	//std::cout << (std::abs(x - finishx) + std::abs(y - (GridHeight-1))) << std::endl;
	return (std::abs(x - finishx) + std::abs(y - (GridHeight - 1)));
}
