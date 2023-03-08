int n;
    std::vector<int> input;
    std::cout << "How many elements? --> " << std::endl;
    std::cin >> n;
    std::cout << n << " elements to input: " << std::endl;
    int in;
    for (int i = 0; i < n; i++){
        std::cin >> in;
        input.push_back(in);
    }

    printVectorInt(input);