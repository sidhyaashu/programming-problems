int linearSearch(Tensor* tensor, int target) {
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                if (tensor->data[i][j][k] == target) {
                    return 1; // Found
                }
            }
        }
    }
    return 0; // Not found
}
