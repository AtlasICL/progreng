if (!infile.is_open()){
        std::cout << "failed to open file" << std::endl;
        EXIT_FAILURE;
    }
    else {
        list_t tmp;
        while (infile >> tmp){
            inputVector.push_back(tmp);
        }
    }