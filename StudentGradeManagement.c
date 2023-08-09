#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Student { // Declare Variable Basic untuk program
    char nama_siswa[100];
    char nis_siswa[100];
    char notelp_siswa[15];
    float nilai_math;
    float nilai_ipa;
    float nilai_bIndo;
    float nilai_bInggris;
    float nilai_senBud;
    bool grades_input; // Untuk check apakah nilai siswa udah diinput atau belum
};

// Hitung Avg Nilai Siswa
float calculateAverage(float nilai_math, float nilai_ipa, float nilai_bIndo, float nilai_bInggris, float nilai_senBud) {
    return (nilai_math + nilai_ipa + nilai_bIndo + nilai_bInggris + nilai_senBud) / 5;
}

// Tampilan Menu Awal
void displayMainMenu() {
    printf("\n==========================================\n");
    printf("SELAMAT DATANG DI PROGRAM GRADE MANAGEMENT\n");
    printf("==========================================\n");
    printf("1. Input Data Siswa\n");
    printf("2. View Data Siswa\n");
    printf("3. Update Data Siswa\n");
    printf("4. Delete Data Siswa\n");
    printf("5. Input Nilai Siswa\n");
    printf("6. View Nilai Siswa\n");
    printf("7. Update Nilai Siswa\n");
    printf("8. Hitung Rata-rata Nilai Kelas\n");
    printf("9. Ranking Siswa\n");
    printf("10. Cari Siswa\n");
    printf("0. Exit\n");
    printf("==========================================\n");
    printf("Pilih: ");
}

// Input Data Siswa
void inputStudentData(struct Student *student) {
    printf("\n==========================================\n");
    printf("INPUT DATA SISWA\n");
    printf("==========================================\n");
    printf("NAMA SISWA: ");
    getchar();
    fgets(student->nama_siswa, sizeof(student->nama_siswa), stdin); // Fgets digunakan untuk membaca string sepanjang sizeof
    strtok(student->nama_siswa, "\n"); // Fungsi Strtok digunakan untuk menghapus baris baru
    printf("NOMOR INDUK SISWA: ");
    fgets(student->nis_siswa, sizeof(student->nis_siswa), stdin); // fungsi -> digunakan untuk mengakses pointer dari struct student
    strtok(student->nis_siswa, "\n");
    printf("NOMOR TELEPON SISWA: ");
    fgets(student->notelp_siswa, sizeof(student->notelp_siswa), stdin);
    strtok(student->notelp_siswa, "\n");
    student->grades_input = false; // Set grades_input menjadi false saat menginput data siswa baru
}

// Update Data Siswa
void updateStudentData(struct Student *student) {
    printf("UPDATE DATA SISWA\n");
    printf("NAMA SISWA: ");
    getchar();
    fgets(student->nama_siswa, sizeof(student->nama_siswa), stdin);
    strtok(student->nama_siswa, "\n");
    printf("NOMOR INDUK SISWA: ");
    fgets(student->nis_siswa, sizeof(student->nis_siswa), stdin);
    strtok(student->nis_siswa, "\n");
    printf("NOMOR TELEPON SISWA: ");
    fgets(student->notelp_siswa, sizeof(student->notelp_siswa), stdin);
    strtok(student->notelp_siswa, "\n");
    printf("Data siswa berhasil diupdate.\n");
}

// Input Nilai Siswa
void inputStudentGrade(struct Student *student) {
    printf("\n==========================================\n");
    printf("INPUT NILAI SISWA\n");
    printf("==========================================\n");
    do {
        printf("NILAI MATEMATIKA: ");
        scanf("%f", &student->nilai_math);
        if (student->nilai_math < 0 || student->nilai_math > 100) {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100.\n");
        }
    } while (student->nilai_math < 0 || student->nilai_math > 100); // User diminta menginput terus menerus selama nilai yang diinput < 0 atau > 100

    do {
        printf("NILAI IPA: ");
        scanf("%f", &student->nilai_ipa);
        if (student->nilai_ipa < 0 || student->nilai_ipa > 100) {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100.\n");
        }
    } while (student->nilai_ipa < 0 || student->nilai_ipa > 100);

    do {
        printf("NILAI B. INDONESIA: ");
        scanf("%f", &student->nilai_bIndo);
        if (student->nilai_bIndo < 0 || student->nilai_bIndo > 100) {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100.\n");
        }
    } while (student->nilai_bIndo < 0 || student->nilai_bIndo > 100);

    do {
        printf("NILAI B. INGGRIS: ");
        scanf("%f", &student->nilai_bInggris);
        if (student->nilai_bInggris < 0 || student->nilai_bInggris > 100) {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100.\n");
        }
    } while (student->nilai_bInggris < 0 || student->nilai_bInggris > 100);

    do {
        printf("NILAI SENI & BUDAYA: ");
        scanf("%f", &student->nilai_senBud);
        if (student->nilai_senBud < 0 || student->nilai_senBud > 100) {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100.\n");
        }
    } while (student->nilai_senBud < 0 || student->nilai_senBud > 100);

    student->grades_input = true; // Set grades_input = true setelah menginput nilai siswa
}

// Display data siswa
void displayStudentData(struct Student *student) {
    printf("NAMA SISWA: %s\n", student->nama_siswa);
    printf("NOMOR INDUK SISWA: %s\n", student->nis_siswa);
    printf("NOMOR TELEPON SISWA: %s\n", student->notelp_siswa);
}

// Display data siswa with ID
void displayStudentDataWithID(struct Student *student, int studentID) {
    printf("ID Siswa: %d\n", studentID);
    displayStudentData(student);
}

// Display data siswa with Avg Nilai
void displayStudentDataWithAverage(struct Student *student, float average) {
    printf("NAMA SISWA: %s\n", student->nama_siswa);
    printf("NOMOR INDUK SISWA: %s\n", student->nis_siswa);
    printf("NOMOR TELEPON SISWA: %s\n", student->notelp_siswa);
    printf("NILAI RATA-RATA: %.2f\n", average);
}

// Display Nilai siswa
void displayStudentGrade(struct Student *student) {
    printf("NAMA SISWA: %s\n", student->nama_siswa);
    printf("NOMOR INDUK SISWA: %s\n", student->nis_siswa);

    if (!student->grades_input) {
        printf("NILAI SISWA BELUM PERNAH DIINPUT\n");
    } else {
        printf("NILAI MATEMATIKA: %.2f\n", student->nilai_math);
        printf("NILAI IPA: %.2f\n", student->nilai_ipa);
        printf("NILAI B. INDONESIA: %.2f\n", student->nilai_bIndo);
        printf("NILAI B. INGGRIS: %.2f\n", student->nilai_bInggris);
        printf("NILAI SENI & BUDAYA: %.2f\n", student->nilai_senBud);
        printf("NILAI RATA-RATA: %.2f\n", calculateAverage(student->nilai_math, student->nilai_ipa, student->nilai_bIndo, student->nilai_bInggris, student->nilai_senBud)); // Rata-rata nilai siswa
    }
}

// Hapus Data Siswa
void deleteStudentData(struct Student **students, int *numStudents, int index) {
    free(students[index]); // Membersihkan data dari id yang diinput
    for (int i = index; i < *numStudents - 1; i++) {
        students[i] = students[i + 1]; // Mereplace id yang sudah dihapus
    }
    (*numStudents)--; // Jumlah siswa berkurang 1
    printf("Data siswa berhasil dihapus.\n");
}

// Hitung Avg Nilai Kelas
void calculateClassAverage(struct Student *students[], int numStudents) {
    if (numStudents == 0) {
        printf("Tidak ada data siswa yang tersedia.\n");
    } else {
        float totalMath = 0, totalIPA = 0, totalBIndo = 0, totalBInggris = 0, totalSenBud = 0;
        for (int i = 0; i < numStudents; i++) { // Untuk setiap nilai siswa untuk matkul x, nilainya di += pada matkul masing-masing
            totalMath += students[i]->nilai_math;
            totalIPA += students[i]->nilai_ipa;
            totalBIndo += students[i]->nilai_bIndo;
            totalBInggris += students[i]->nilai_bInggris;
            totalSenBud += students[i]->nilai_senBud;
        }

        float classAverageMath = totalMath / numStudents; // total nilai matkul dari semua siswa dibagi jumlah siswa
        float classAverageIPA = totalIPA / numStudents;
        float classAverageBIndo = totalBIndo / numStudents;
        float classAverageBInggris = totalBInggris / numStudents;
        float classAverageSenBud = totalSenBud / numStudents;
        float classAverage = (classAverageMath + classAverageIPA + classAverageBIndo + classAverageBInggris + classAverageSenBud) / 5; // Rata rata nilai kelas

        printf("\n==========================================\n");
        printf("NILAI RATA-RATA KELAS\n");
        printf("==========================================\n");
        printf("NILAI RATA-RATA MATEMATIKA: %.2f\n", classAverageMath);
        printf("NILAI RATA-RATA IPA: %.2f\n", classAverageIPA);
        printf("NILAI RATA-RATA B. INDONESIA: %.2f\n", classAverageBIndo);
        printf("NILAI RATA-RATA B. INGGRIS: %.2f\n", classAverageBInggris);
        printf("NILAI RATA-RATA SENI & BUDAYA: %.2f\n", classAverageSenBud);
        printf("==========================================\n");
        printf("NILAI RATA-RATA KELAS: %.2f\n", classAverage);
        printf("==========================================\n");
    }
}

// Sorting Berdasarkan Avg Nilai
void sortByAverageGrade(struct Student *students[], int numStudents, int sortDirection) {
    struct Student *tempStudents[numStudents]; // deklarasi tempStudent untuk menampung sorting ranking secara ascending dan descending
    for (int i = 0; i < numStudents; i++) {
        tempStudents[i] = students[i];
    }

    // Bubble Sort
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) { // selama dalam repetation, akan ada 2 siswa yang dibandingkan untuk satu kali perbandingan, dibandingkan berdasarkan rata-rata nilai
            float avg1 = calculateAverage(tempStudents[j]->nilai_math, tempStudents[j]->nilai_ipa, tempStudents[j]->nilai_bIndo, tempStudents[j]->nilai_bInggris, tempStudents[j]->nilai_senBud);
            float avg2 = calculateAverage(tempStudents[j + 1]->nilai_math, tempStudents[j + 1]->nilai_ipa, tempStudents[j + 1]->nilai_bIndo, tempStudents[j + 1]->nilai_bInggris, tempStudents[j + 1]->nilai_senBud);
            // sortDirection ini menentukan kondisi, untuk dua nilai yang dibandingkan apakah harus ditukar ketika nilainya lebih besar atau lebih kecil? sehingga digunakan +1 atau -1
            if (sortDirection == 1) { // Ascending
                if (avg1 > avg2) {
                    struct Student *temp = tempStudents[j]; // jadi tempStudent dibuat untuk mengatasi bug sebelumnya, dimana id siswa tertukar ketika dilakukan sort ascending maupun descending
                    tempStudents[j] = tempStudents[j + 1];
                    tempStudents[j + 1] = temp;
                }
            } else if (sortDirection == -1) { // Descending
                if (avg1 < avg2) {
                    struct Student *temp = tempStudents[j];
                    tempStudents[j] = tempStudents[j + 1];
                    tempStudents[j + 1] = temp;
                }
            }
        }
    }

    // Display peringkat siswa dan Avg Nilai
    printf("\n==========================================\n");
    printf("PERINGKAT SISWA BERDASARKAN NILAI RATA-RATA\n");
    printf("==========================================\n");
    for (int i = 0; i < numStudents; i++) { // repetation untuk menampilkan ranking seluruh siswa di kelas
        float average = calculateAverage(tempStudents[i]->nilai_math, tempStudents[i]->nilai_ipa, tempStudents[i]->nilai_bIndo, tempStudents[i]->nilai_bInggris, tempStudents[i]->nilai_senBud);
        displayStudentDataWithAverage(tempStudents[i], average); // tampilkan ranking dan nilai rata-rata siswa tersebut
        printf("RANKING: %d\n", i + 1);
        printf("==========================================\n");
    }
}


// Search ID atau Nama
void searchStudent(struct Student *students[], int numStudents, char *query) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (strstr(students[i]->nama_siswa, query) || strstr(students[i]->nis_siswa, query)) { // strstr digunakan untuk mencari query dari nama siswa maupun nisnya
            printf("Hasil Pencarian:\n");
            displayStudentDataWithID(students[i], i + 1);
            printf("\n");
            found = true; // jika ditemukan, bool found diset sebagai true untuk if di bawah
        }
    }

    if (!found) {
        printf("Data siswa tidak ditemukan.\n"); // jika nilai foundnya = false maka line ini ditampilkan
    }
}

int main() {
    struct Student *students[100]; // Array untuk menyimpan data siswa maks 100
    int numStudents = 0; // Jumlah data siswa yang tersimpan

    int menuChoice;
    int sortChoice;

    do {
        displayMainMenu();
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1: // Input Data Siswa
                students[numStudents] = (struct Student *)malloc(sizeof(struct Student));
                inputStudentData(students[numStudents]);
                numStudents++;
                printf("Data siswa berhasil diinput.\n");
                break;
            case 2: // View Data Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("DATA SISWA\n");
                    printf("==========================================\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1);
                        printf("\n"); // untuk setiap data siswa ke 0 < jumlah siswa akan ditampilkan datanya beserta ID yang didapat setelah menginput data
                    }
                }
                break;
            case 3: // Update Data Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("UPDATE DATA SISWA\n");
                    printf("==========================================\n");
                    printf("Pilih Siswa:\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1); // menampilkan semua data siswa yang akan dipilih untuk diupdate
                    }
                    printf("0. Back\n");
                    printf("Masukkan ID Siswa yang akan diupdate: ");
                    int studentId;
                    scanf("%d", &studentId);

                    if (studentId >= 1 && studentId <= numStudents) { // data yang tersedia adalah 1 sampai dengan jumlah siswa
                        updateStudentData(students[studentId - 1]); // dilakukan deklarasi -1 karena program dihitung mulai dari angka 0
                    } else if (studentId != 0) {
                        printf("ID Siswa tidak valid.\n"); // Jika student tidak ditemukan
                    }
                }
                break;
            case 4: // Delete Data Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("DELETE DATA SISWA\n");
                    printf("==========================================\n");
                    printf("Pilih Siswa:\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1);
                    }
                    printf("0. Back\n");
                    printf("Masukkan ID Siswa yang akan dihapus: ");
                    int studentId;
                    scanf("%d", &studentId);

                    if (studentId >= 1 && studentId <= numStudents) {
                        deleteStudentData(students, &numStudents, studentId - 1); // menghapus data siswa yang idnya diinput
                    } else if (studentId != 0) {
                        printf("ID Siswa tidak valid.\n");
                    }
                }
                break;
            case 5: // Input Nilai Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("INPUT NILAI SISWA\n");
                    printf("==========================================\n");
                    printf("Pilih Siswa:\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1);
                    }
                    printf("0. Back\n");
                    printf("Masukkan ID Siswa: ");
                    int studentId;
                    scanf("%d", &studentId);

                    if (studentId >= 1 && studentId <= numStudents) {
                        inputStudentGrade(students[studentId - 1]); // melakukan fungsi inputStudentGrade
                        printf("Data nilai siswa berhasil diinput.\n");
                    } else if (studentId != 0) {
                        printf("ID Siswa tidak valid.\n");
                    }
                }
                break;
            case 6: // View Nilai Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("NILAI SISWA\n");
                    printf("==========================================\n");
                    printf("Pilih Siswa:\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1);
                    }
                    printf("0. Back\n");
                    printf("Masukkan ID Siswa: ");
                    int studentId;
                    scanf("%d", &studentId);

                    if (studentId >= 1 && studentId <= numStudents) {
                        displayStudentGrade(students[studentId - 1]);
                    } else if (studentId != 0) {
                        printf("ID Siswa tidak valid.\n");
                    }
                }
                break;
            case 7: // Update Nilai Siswa
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("UPDATE NILAI SISWA\n");
                    printf("==========================================\n");
                    printf("Pilih Siswa:\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentDataWithID(students[i], i + 1);
                    }
                    printf("0. Back\n");
                    printf("Masukkan ID Siswa: ");
                    int studentId;
                    scanf("%d", &studentId);

                    if (studentId >= 1 && studentId <= numStudents) {
                        if (!students[studentId - 1]->grades_input) { // Jika grade inputnya false, artinya nilai belum diinputkan sehingga tidak bisa mengupdate nilai
                            printf("Nilai siswa belum diinputkan. Silakan input nilai terlebih dahulu.\n");
                        } else {
                            inputStudentGrade(students[studentId - 1]); // Notifikasi jika berhasil
                            printf("Data nilai siswa berhasil diupdate.\n");
                        }
                    } else if (studentId != 0) {
                        printf("ID Siswa tidak valid.\n"); // Jika siswa yang dipilih tidak ada
                    }
                }
                break;
            case 8: // Hitung Avg Kelas
                calculateClassAverage(students, numStudents);
                break;
            case 9: // Sorting Ranking
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("SORTING SISWA BERDASARKAN NILAI RATA-RATA\n");
                    printf("==========================================\n");
                    printf("1. Descending (Dihitung dari Belakang)\n");
                    printf("2. Ascending (Dihitung dari Depan)\n");
                    printf("0. Back\n");
                    printf("Pilih jenis sorting: ");
                    scanf("%d", &sortChoice); // Pemilihan jenis sorting

                    if (sortChoice == 1) {
                        sortByAverageGrade(students, numStudents, 1);
                        printf("Sorting descending selesai.\n");
                    } else if (sortChoice == 2) {
                        sortByAverageGrade(students, numStudents, -1);
                        printf("Sorting ascending selesai.\n");
                    } else if (sortChoice != 0) {
                        printf("Pilihan tidak valid.\n");
                    }
                }
                break;
            case 10: // Search Name or ID
                if (numStudents == 0) {
                    printf("Tidak ada data siswa yang tersedia.\n");
                } else {
                    printf("\n==========================================\n");
                    printf("PENCARIAN SISWA\n");
                    printf("==========================================\n");
                    printf("Masukkan Nama atau ID Siswa: ");
                    char query[100]; // menampung sebesar 100 karakter
                    getchar();
                    fgets(query, sizeof(query), stdin); // menampung query yang diinput
                    strtok(query, "\n"); // menghapus new line dari query
                    searchStudent(students, numStudents, query); // melakukan fungsu search pada query
                }
                break;
            case 0: // Exit
                printf("Terima kasih telah menggunakan program Grade Management.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (menuChoice != 0);

    // Mengembalikan Nilai i setelah data Siswa dihapus
    for (int i = 0; i < numStudents; i++) {
        free(students[i]);
    }

    return 0;
}
