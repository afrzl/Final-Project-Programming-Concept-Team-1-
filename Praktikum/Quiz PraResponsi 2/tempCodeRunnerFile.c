
        fwrite(nim, sizeof(int), 5, fPtr); //menulis struct DataMahasiswa ke dalam file
        fread(read_nim, sizeof(int), 5, fPtr);
    }