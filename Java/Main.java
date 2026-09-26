import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Scanner digunakan untuk menerima input dari user.
    static Scanner input = new Scanner(System.in);

    // =====================================================
    // METHOD INPUT INTEGER
    // =====================================================

    // Method untuk menerima input berupa bilangan bulat.
    // Jika input bukan angka, user diminta mengulang.
    static int inputInteger(String pesan) {
        while (true) {
            try {
                System.out.print(pesan);
                int nilai = Integer.parseInt(input.nextLine());

                return nilai;
            } catch (Exception e) {
                System.out.println("Error: input harus berupa angka.");
            }
        }
    }

    // =====================================================
    // METHOD INPUT STRING
    // =====================================================

    // Method untuk menerima input berupa String.
    // Input kosong tidak diperbolehkan.
    static String inputString(String pesan) {
        while (true) {
            System.out.print(pesan);
            String nilai = input.nextLine().trim();

            if (!nilai.isEmpty()) {
                return nilai;
            }

            System.out.println("Error: input tidak boleh kosong.");
        }
    }

    // =====================================================
    // METHOD INPUT INTEGER RANGE
    // =====================================================

    // Method untuk menerima bilangan bulat yang harus
    // berada di antara nilai minimum dan maksimum.
    static int inputIntegerRange(
            String pesan,
            int minimum,
            int maksimum) {
        while (true) {
            int nilai = inputInteger(pesan);

            if (nilai >= minimum && nilai <= maksimum) {
                return nilai;
            }

            System.out.println(
                    "Error: nilai harus berada di antara "
                            + minimum + " dan " + maksimum + ".");
        }
    }

    // =====================================================
    // METHOD CEK ID
    // =====================================================

    // Method untuk mengecek apakah ID sudah digunakan
    // oleh object film yang terdapat di dalam ArrayList.
    static boolean idSudahAda(
            ArrayList<FilmAnimasi> daftarFilm,
            String id) {
        for (FilmAnimasi film : daftarFilm) {
            if (film.getId().equals(id)) {
                return true;
            }
        }

        return false;
    }

    // =====================================================
    // METHOD INPUT ID UNIK
    // =====================================================

    // Method untuk menerima ID baru.
    // ID harus diisi dan tidak boleh sama dengan ID
    // yang sudah dimiliki object lain.
    static String inputIdUnik(
            ArrayList<FilmAnimasi> daftarFilm) {
        while (true) {
            String id = inputString("ID              : ");

            if (!idSudahAda(daftarFilm, id)) {
                return id;
            }

            System.out.println(
                    "Error: ID sudah digunakan. "
                            + "Silakan gunakan ID lain.");
        }
    }

    // =====================================================
    // PROSEDUR TAMBAH DATA
    // =====================================================

    // Prosedur untuk menerima input data FilmAnimasi,
    // membuat object baru, kemudian memasukkannya
    // ke dalam ArrayList daftarFilm.
    static void tambahFilm(
            ArrayList<FilmAnimasi> daftarFilm) {
        System.out.println("\n===== TAMBAH FILM ANIMASI =====");

        // -------------------------
        // Atribut KaryaSeni
        // -------------------------

        String id = inputIdUnik(daftarFilm);

        String judul = inputString(
                "Judul           : ");

        int tahunRilis = inputIntegerRange(
                "Tahun Rilis     : ",
                1900,
                2100);

        String pencipta = inputString(
                "Pencipta        : ");

        // -------------------------
        // Atribut Film
        // -------------------------

        String genre = inputString(
                "Genre           : ");

        int durasi = inputIntegerRange(
                "Durasi (menit)  : ",
                0,
                600);

        int harga = inputIntegerRange(
                "Harga           : Rp",
                0,
                1000000);

        // -------------------------
        // Atribut FilmAnimasi
        // -------------------------

        String studioAnimasi = inputString(
                "Studio Animasi  : ");

        String teknikAnimasi = inputString(
                "Teknik Animasi  : ");

        // Meminta jumlah pengisi suara.
        int jumlahPengisiSuara = inputIntegerRange(
                "Jumlah Pengisi Suara: ",
                1,
                100);

        // ArrayList untuk menyimpan beberapa
        // nama pengisi suara.
        ArrayList<String> pengisiSuara = new ArrayList<>();

        // Memasukkan setiap nama pengisi suara
        // ke dalam ArrayList.
        for (int i = 0; i < jumlahPengisiSuara; i++) {
            String nama = inputString(
                    "Pengisi Suara " + (i + 1) + ": ");

            pengisiSuara.add(nama);
        }

        // Membuat object FilmAnimasi baru menggunakan
        // seluruh data yang telah dimasukkan user.
        FilmAnimasi filmBaru = new FilmAnimasi(
                id,
                judul,
                tahunRilis,
                pencipta,
                genre,
                durasi,
                harga,
                studioAnimasi,
                teknikAnimasi,
                pengisiSuara);

        // Menambahkan object baru ke dalam ArrayList.
        daftarFilm.add(filmBaru);

        System.out.println(
                "\nData film berhasil ditambahkan!");
    }

    // =====================================================
    // METHOD MEMBUAT GARIS TABEL
    // =====================================================

    // Method untuk membuat garis horizontal tabel.
    // Panjang setiap kolom disesuaikan dengan lebar
    // kolom yang telah dihitung sebelumnya.
    static void buatGaris(int[] lebarKolom) {
        System.out.print("+");

        for (int lebar : lebarKolom) {
            System.out.print(
                    "-".repeat(lebar + 2) + "+");
        }

        System.out.println();
    }

    // =====================================================
    // PROSEDUR TAMPILKAN DATA
    // =====================================================

    // Prosedur untuk menampilkan seluruh object FilmAnimasi dalam satu tabel.
    // Tabel mencakup seluruh atribut dari:
    // 1. KaryaSeni
    // 2. Film
    // 3. FilmAnimasi
    // Lebar setiap kolom dibuat dinamis berdasarkan
    // data terpanjang pada kolom tersebut.
    static void tampilkanSemuaFilm(
            ArrayList<FilmAnimasi> daftarFilm) {
        // Jika ArrayList kosong, tidak ada data
        // yang dapat ditampilkan.
        if (daftarFilm.isEmpty()) {
            System.out.println(
                    "\nBelum ada data film.");

            return;
        }

        // Header tabel berisi seluruh atribut
        // dari ketiga class.
        String[] header = {
                "ID",
                "Judul",
                "Tahun Rilis",
                "Pencipta",
                "Genre",
                "Durasi",
                "Harga",
                "Studio Animasi",
                "Teknik Animasi",
                "Pengisi Suara"
        };

        // ArrayList untuk menyimpan data yang
        // akan ditampilkan pada setiap baris.
        ArrayList<String[]> data = new ArrayList<>();

        // Mengambil data dari setiap object.
        for (FilmAnimasi film : daftarFilm) {
            // Menggabungkan seluruh pengisi suara
            // menjadi satu String agar dapat ditampilkan
            // dalam satu cell tabel.
            String daftarVoiceActor = String.join(
                    ", ",
                    film.getPengisiSuara());

            String[] baris = {
                    film.getId(),
                    film.getJudul(),
                    String.valueOf(
                            film.getTahunRilis()),
                    film.getPencipta(),
                    film.getGenre(),
                    film.getDurasi() + " menit",
                    "Rp" + film.getHarga(),
                    film.getStudioAnimasi(),
                    film.getTeknikAnimasi(),
                    daftarVoiceActor
            };

            data.add(baris);
        }

        // =================================================
        // MENGHITUNG LEBAR SETIAP KOLOM
        // =================================================

        // Lebar awal setiap kolom mengikuti
        // panjang header.
        int[] lebarKolom = new int[header.length];

        for (int i = 0; i < header.length; i++) {
            lebarKolom[i] = header[i].length();
        }

        // Membandingkan panjang data dengan lebar
        // kolom saat ini.
        for (String[] baris : data) {
            for (int i = 0; i < baris.length; i++) {
                if (baris[i].length() > lebarKolom[i]) {
                    lebarKolom[i] = baris[i].length();
                }
            }
        }

        // =================================================
        // MENAMPILKAN TABEL
        // =================================================

        System.out.println();
        System.out.println(
                "========================================== "
                        + "DAFTAR FILM ANIMASI "
                        + "==========================================");

        // Garis bagian atas tabel.
        buatGaris(lebarKolom);

        // Menampilkan header.
        System.out.print("|");

        for (int i = 0; i < header.length; i++) {
            System.out.printf(
                    " %-" + lebarKolom[i] + "s |",
                    header[i]);
        }

        System.out.println();

        // Garis pemisah antara header dan data.
        buatGaris(lebarKolom);

        // Menampilkan seluruh data.
        for (String[] baris : data) {
            System.out.print("|");

            for (int i = 0; i < baris.length; i++) {
                System.out.printf(
                        " %-" + lebarKolom[i] + "s |",
                        baris[i]);
            }

            System.out.println();
        }

        // Garis bagian bawah tabel.
        buatGaris(lebarKolom);
    }

    // =====================================================
    // MAIN PROGRAM
    // =====================================================

    public static void main(String[] args) {
        // =================================================
        // 5 OBJECT AWAL
        // =================================================

        // Lima object awal dibuat sebelum program
        // menerima input dari user sesuai ketentuan tugas.

        ArrayList<String> voiceActor1 = new ArrayList<>();

        voiceActor1.add("Natsuki Hanae");
        voiceActor1.add("Akari Kito");
        voiceActor1.add("Satoshi Hino");

        FilmAnimasi film1 = new FilmAnimasi(
                "F001",
                "Demon Slayer: Mugen Train",
                2020,
                "Koyoharu Gotouge",
                "Action, Fantasy",
                117,
                50000,
                "Ufotable",
                "2D Digital",
                voiceActor1);

        ArrayList<String> voiceActor2 = new ArrayList<>();

        voiceActor2.add("Megumi Ogata");
        voiceActor2.add("Kana Hanazawa");
        voiceActor2.add("Yuichi Nakamura");

        FilmAnimasi film2 = new FilmAnimasi(
                "F002",
                "Jujutsu Kaisen 0",
                2021,
                "Gege Akutami",
                "Action, Fantasy",
                105,
                45000,
                "MAPPA",
                "2D Digital",
                voiceActor2);

        ArrayList<String> voiceActor3 = new ArrayList<>();

        voiceActor3.add("Ryunosuke Kamiki");
        voiceActor3.add("Mone Kamishiraishi");

        FilmAnimasi film3 = new FilmAnimasi(
                "F003",
                "Your Name",
                2016,
                "Makoto Shinkai",
                "Romance, Fantasy",
                106,
                45000,
                "CoMix Wave Films",
                "2D Digital",
                voiceActor3);

        ArrayList<String> voiceActor4 = new ArrayList<>();

        voiceActor4.add("Kaori Nazuka");
        voiceActor4.add("Suichi Ikeda");
        voiceActor4.add("Mayumi Tanaka");

        FilmAnimasi film4 = new FilmAnimasi(
                "F004",
                "One Piece Film: Red",
                2022,
                "Eiichiro Oda",
                "Action, Advanture",
                115,
                50000,
                "Toei Animation",
                "2D Digital",
                voiceActor4);

        ArrayList<String> voiceActor5 = new ArrayList<>();

        voiceActor5.add("Soma Santoki");
        voiceActor5.add("Masaki Suda");
        voiceActor5.add("Takuya Kimura");

        FilmAnimasi film5 = new FilmAnimasi(
                "F005",
                "The Boy and the Heron",
                2023,
                "Hayao Miyazaki",
                "Fantasy, Adventure",
                124,
                55000,
                "Studio Ghibli",
                "2D Hand-Drawn",
                voiceActor5);

        // =================================================
        // ARRAYLIST OF OBJECT
        // =================================================

        // ArrayList digunakan untuk menyimpan seluruh
        // object FilmAnimasi.
        // Lima object awal dimasukkan sebelum user
        // dapat menambahkan data baru.
        ArrayList<FilmAnimasi> daftarFilm = new ArrayList<>();

        daftarFilm.add(film1);
        daftarFilm.add(film2);
        daftarFilm.add(film3);
        daftarFilm.add(film4);
        daftarFilm.add(film5);

        // =================================================
        // MENU PROGRAM
        // =================================================

        // Program akan terus berjalan sampai user
        // memilih menu 0 untuk keluar.
        while (true) {
            System.out.println("\n==============================");
            System.out.println("      MENU FILM ANIMASI       ");
            System.out.println("==============================");

            System.out.println("1. Tambah Data");
            System.out.println("2. Tampilkan Data");
            System.out.println("0. Keluar");

            int pilihan = inputInteger(
                    "Pilihan: ");

            if (pilihan == 1) {
                tambahFilm(daftarFilm);
            } else if (pilihan == 2) {
                tampilkanSemuaFilm(daftarFilm);
            } else if (pilihan == 0) {
                System.out.println(
                        "\nProgram selesai.");

                break;
            } else {
                System.out.println(
                        "Error: pilihan menu tidak tersedia.");
            }
        }

        // Menutup Scanner setelah program selesai.
        input.close();
    }
}