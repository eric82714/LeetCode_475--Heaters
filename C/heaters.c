int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){ 
    qsort(houses, housesSize, sizeof(int), compare);
    qsort(heaters, heatersSize, sizeof(int), compare);
        
    if(heatersSize == 1)
        return fmax(heaters[0]-houses[0], houses[housesSize-1]-heaters[0]);
    else {
        int radius = 0;
        int pos = 0;
           
        for(int i = 0; i < housesSize; i++) {
            int cur = houses[i];
                
            while(pos < heatersSize - 1 && abs(heaters[pos + 1] - cur) <= abs(heaters[pos] - cur))                     
                pos ++;
                
            radius = fmax(radius, abs(heaters[pos] - cur));
        }
        
        return radius;
    }
}
