<?php

// =========================
// INCLUDE CLASS
// =========================

// Memanggil class dari parent paling atas sampai child.
// Urutan diperlukan karena Film merupakan turunan dari KaryaSeni,
// sedangkan FilmAnimasi merupakan turunan dari Film.
require_once "KaryaSeni.php";
require_once "Film.php";
require_once "FilmAnimasi.php";


// =========================
// SESSION
// =========================

// Session digunakan untuk menyimpan data FilmAnimasi
// selama user masih berada dalam session yang sama.
session_start();


// =========================
// DATA AWAL
// =========================

// Jika session belum memiliki data film,
// maka dibuat 5 object awal terlebih dahulu.
//
// Lima object ini merupakan object yang wajib tersedia
// sebelum user melakukan input data tambahan.
if (!isset($_SESSION['films'])) {

    $_SESSION['films'] = [

        new FilmAnimasi(
            "F001",
            "Demon Slayer: Mugen Train",
            2020,
            "Koyoharu Gotouge",
            "Action, Fantasy",
            117,
            50000,
            "Ufotable",
            "2D Digital",
            [
                "Natsuki Hanae",
                "Akari Kito",
                "Satoshi Hino"
            ],
            "images/demon-slayer.jpg"
        ),

        new FilmAnimasi(
            "F002",
            "Jujutsu Kaisen 0",
            2021,
            "Gege Akutami",
            "Action, Fantasy",
            105,
            45000,
            "MAPPA",
            "2D Digital",
            [
                "Megumi Ogata",
                "Kana Hanazawa",
                "Yuichi Nakamura"
            ],
            "images/jujutsu-kaisen-0.jpg"
        ),

        new FilmAnimasi(
            "F003",
            "Your Name",
            2016,
            "Makoto Shinkai",
            "Romance, Fantasy",
            106,
            45000,
            "CoMix Wave Films",
            "2D Digital",
            [
                "Ryunosuke Kamiki",
                "Mone Kamishiraishi"
            ],
            "images/your-name.jpg"
        ),

        new FilmAnimasi(
            "F004",
            "One Piece Film: Red",
            2022,
            "Eiichiro Oda",
            "Action, Adventure",
            115,
            50000,
            "Toei Animation",
            "2D Digital",
            [
                "Kaori Nazuka",
                "Shuichi Ikeda",
                "Mayumi Tanaka"
            ],
            "images/one-piece-red.jpg"
        ),

        new FilmAnimasi(
            "F005",
            "The Boy and the Heron",
            2023,
            "Hayao Miyazaki",
            "Fantasy, Adventure",
            124,
            55000,
            "Studio Ghibli",
            "2D Hand-Drawn",
            [
                "Soma Santoki",
                "Masaki Suda",
                "Takuya Kimura"
            ],
            "images/the-boy-and-the-heron.jpg"
        )
    ];
}


// =========================
// PROSES TAMBAH DATA
// =========================

// Mengecek apakah form dikirim menggunakan method POST.
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // Mengambil data dari form.
    // trim() digunakan untuk menghapus spasi berlebih
    // pada awal dan akhir input.
    $id = trim($_POST['id']);
    $judul = trim($_POST['judul']);
    $tahunRilis = (int) $_POST['tahunRilis'];
    $pencipta = trim($_POST['pencipta']);
    $genre = trim($_POST['genre']);
    $durasi = (int) $_POST['durasi'];
    $harga = (int) $_POST['harga'];
    $studioAnimasi = trim($_POST['studioAnimasi']);
    $teknikAnimasi = trim($_POST['teknikAnimasi']);
    $foto_produk = trim($_POST['foto_produk']);

    // Pengisi suara dimasukkan satu nama per baris.
    // explode() digunakan untuk memisahkan setiap nama
    // berdasarkan baris baru.
    $pengisiSuara = explode("\n", $_POST['pengisiSuara']);

    // Menghapus spasi berlebih pada setiap nama.
    $pengisiSuara = array_map('trim', $pengisiSuara);

    // Menghapus baris kosong dari array pengisi suara.
    $pengisiSuara = array_filter(
        $pengisiSuara,
        function ($nama) {
            return $nama != "";
        }
    );


    // =========================
    // VALIDASI
    // =========================

    $error = "";

    // Mengecek apakah ID sudah digunakan.
    foreach ($_SESSION['films'] as $film) {

        if ($film->getId() == $id) {
            $error = "Error: ID film sudah digunakan.";
            break;
        }
    }

    // Mengecek input wajib.
    if (
        $error == "" &&
        (
            $id == "" ||
            $judul == "" ||
            $pencipta == "" ||
            $genre == "" ||
            $studioAnimasi == "" ||
            $teknikAnimasi == "" ||
            $foto_produk == ""
        )
    ) {
        $error = "Error: semua data wajib diisi.";
    }

    // Mengecek tahun rilis.
    if ($error == "" && ($tahunRilis < 1900 || $tahunRilis > 2100)) {
        $error = "Error: tahun rilis harus berada pada 1900 sampai 2100.";
    }

    // Mengecek durasi.
    if ($error == "" && ($durasi < 0 || $durasi > 600)) {
        $error = "Error: durasi harus berada pada 0 sampai 600 menit.";
    }

    // Mengecek harga.
    if ($error == "" && ($harga < 0 || $harga > 1000000)) {
        $error = "Error: harga harus berada pada Rp0 sampai Rp1000000.";
    }

    // Mengecek jumlah pengisi suara.
    if ($error == "" && count($pengisiSuara) == 0) {
        $error = "Error: minimal terdapat satu pengisi suara.";
    }


    // =========================
    // MENAMBAHKAN DATA
    // =========================

    // Jika tidak terdapat error, buat object FilmAnimasi baru
    // kemudian masukkan object tersebut ke array session.
    if ($error == "") {

        $filmBaru = new FilmAnimasi(
            $id,
            $judul,
            $tahunRilis,
            $pencipta,
            $genre,
            $durasi,
            $harga,
            $studioAnimasi,
            $teknikAnimasi,
            $pengisiSuara,
            $foto_produk
        );

        $_SESSION['films'][] = $filmBaru;

        // Redirect digunakan agar data POST tidak dikirim ulang
        // ketika user melakukan refresh halaman.
        header("Location: index.php");
        exit;
    }
}

?>


<!DOCTYPE html>
<html lang="id">

<head>

    <meta charset="UTF-8">

    <title>Data Film Animasi</title>


    <style>
        /* =========================
           DASAR HALAMAN
           ========================= */

        * {
            box-sizing: border-box;
        }

        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 30px;
            color: #222;
        }

        h1 {
            text-align: center;
            margin-bottom: 30px;
        }

        h2 {
            margin-top: 0;
            margin-bottom: 20px;
        }


        /* =========================
           FORM
           ========================= */

        .form-container {
            max-width: 750px;
            margin: 0 auto 35px auto;
            background-color: white;
            padding: 25px;
            border-radius: 10px;
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1);
        }

        .form-group {
            margin-bottom: 15px;
        }

        label {
            display: block;
            font-weight: bold;
            margin-bottom: 6px;
        }

        input,
        textarea {
            width: 100%;
            padding: 9px;
            border: 1px solid #bbb;
            border-radius: 5px;
            font-family: Arial, sans-serif;
            font-size: 14px;
        }

        input:focus,
        textarea:focus {
            outline: none;
            border-color: #555;
        }

        textarea {
            resize: vertical;
        }

        button {
            padding: 10px 18px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-weight: bold;
        }

        button:hover {
            opacity: 0.85;
        }


        /* =========================
           PESAN ERROR
           ========================= */

        .error {
            background-color: #ffe5e5;
            border: 1px solid #ff9999;
            padding: 10px;
            border-radius: 5px;
            color: #b00000;
            margin-bottom: 15px;
        }


        /* =========================
           TABEL
           ========================= */

        .table-container {
            background-color: white;
            padding: 15px;
            border-radius: 10px;

            /* Jika tabel terlalu lebar, user dapat
               melakukan scroll secara horizontal. */
            overflow-x: auto;

            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1);
        }

        table {
            border-collapse: collapse;
            width: 100%;

            /* Menjaga tabel tetap memiliki ruang
               yang cukup untuk seluruh kolom. */
            min-width: 1100px;
        }

        th,
        td {
            border: 1px solid #ccc;
            padding: 10px;

            /* Isi kolom tidak dipotong menjadi beberapa
               baris sehingga data tetap mudah dibaca. */
            white-space: nowrap;
        }

        th {
            background-color: #eee;
            text-align: center;
        }

        td {
            background-color: white;
        }

        /* Memberikan efek sederhana ketika cursor
           diarahkan ke salah satu baris. */
        tr:hover td {
            background-color: #f8f8f8;
        }
    </style>

</head>


<body>


    <h1>DATA FILM ANIMASI</h1>


    <!-- =========================
         FORM TAMBAH DATA
         ========================= -->

    <div class="form-container">

        <h2>Tambah Data Film Animasi</h2>


        <!-- Menampilkan pesan error jika validasi gagal. -->
        <?php if (isset($error) && $error != ""): ?>

            <div class="error">
                <?php echo htmlspecialchars($error); ?>
            </div>

        <?php endif; ?>


        <form method="POST">


            <!-- ID -->

            <div class="form-group">

                <label>ID</label>

                <input type="text" name="id" value="<?php echo htmlspecialchars($id ?? ''); ?>" required>

            </div>


            <!-- JUDUL -->

            <div class="form-group">

                <label>Judul</label>

                <input type="text" name="judul" value="<?php echo htmlspecialchars($judul ?? ''); ?>" required>

            </div>


            <!-- TAHUN RILIS -->

            <div class="form-group">

                <label>Tahun Rilis</label>

                <input type="number" name="tahunRilis" value="<?php echo htmlspecialchars($tahunRilis ?? ''); ?>"
                    min="1900" max="2100" required>

            </div>


            <!-- PENCIPTA -->

            <div class="form-group">

                <label>Pencipta</label>

                <input type="text" name="pencipta" value="<?php echo htmlspecialchars($pencipta ?? ''); ?>" required>

            </div>


            <!-- GENRE -->

            <div class="form-group">

                <label>Genre</label>

                <input type="text" name="genre" value="<?php echo htmlspecialchars($genre ?? ''); ?>" required>

            </div>


            <!-- DURASI -->

            <div class="form-group">

                <label>Durasi (menit)</label>

                <input type="number" name="durasi" value="<?php echo htmlspecialchars($durasi ?? ''); ?>" min="0"
                    max="600" required>

            </div>


            <!-- HARGA -->

            <div class="form-group">

                <label>Harga</label>

                <input type="number" name="harga" value="<?php echo htmlspecialchars($harga ?? ''); ?>" min="0"
                    max="1000000" required>

            </div>


            <!-- STUDIO ANIMASI -->

            <div class="form-group">

                <label>Studio Animasi</label>

                <input type="text" name="studioAnimasi" value="<?php echo htmlspecialchars($studioAnimasi ?? ''); ?>"
                    required>

            </div>


            <!-- TEKNIK ANIMASI -->

            <div class="form-group">

                <label>Teknik Animasi</label>

                <input type="text" name="teknikAnimasi" value="<?php echo htmlspecialchars($teknikAnimasi ?? ''); ?>"
                    required>

            </div>


            <!-- PENGISI SUARA -->

            <div class="form-group">

                <label>Pengisi Suara</label>

                <!-- Setiap pengisi suara ditulis pada baris
                     yang berbeda. Data tersebut nantinya
                     diubah menjadi array di PHP. -->
                <textarea name="pengisiSuara" rows="4" placeholder="Nama pengisi suara 1&#10;Nama pengisi suara 2"
                    required><?php
                    echo htmlspecialchars(
                        $_POST['pengisiSuara'] ?? ''
                    );
                    ?></textarea>

            </div>


            <!-- FOTO PRODUK -->

            <div class="form-group">

                <label>Foto Produk</label>

                <!-- Atribut foto_produk khusus digunakan
                     pada versi PHP sesuai ketentuan tugas.
                     Nilainya berupa path file lokal. -->
                <input type="text" name="foto_produk" value="<?php echo htmlspecialchars($foto_produk ?? ''); ?>"
                    placeholder="images/nama-file.jpg" required>

            </div>


            <!-- TOMBOL -->

            <button type="submit">
                Tambah Data
            </button>


        </form>

    </div>


    <!-- =========================
         TABEL DATA
         ========================= -->

    <div class="table-container">

        <h2>Daftar Film Animasi</h2>


        <table>

            <thead>

                <tr>

                    <th>ID</th>
                    <th>Judul</th>
                    <th>Tahun Rilis</th>
                    <th>Pencipta</th>
                    <th>Genre</th>
                    <th>Durasi</th>
                    <th>Harga</th>
                    <th>Studio Animasi</th>
                    <th>Teknik Animasi</th>
                    <th>Pengisi Suara</th>
                    <th>Foto Produk</th>

                </tr>

            </thead>


            <tbody>

                <?php foreach ($_SESSION['films'] as $film): ?>

                    <tr>

                        <td>
                            <?php echo htmlspecialchars($film->getId()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getJudul()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getTahunRilis()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getPencipta()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getGenre()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getDurasi()); ?>
                            menit
                        </td>

                        <td>
                            Rp<?php echo htmlspecialchars($film->getHarga()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getStudioAnimasi()); ?>
                        </td>

                        <td>
                            <?php echo htmlspecialchars($film->getTeknikAnimasi()); ?>
                        </td>

                        <td>
                            <?php
                            echo htmlspecialchars(
                                implode(
                                    ", ",
                                    $film->getPengisiSuara()
                                )
                            );
                            ?>
                        </td>

                        <td>
                            <img src="<?php echo htmlspecialchars($film->getFotoProduk()); ?>"
                                alt="<?php echo htmlspecialchars($film->getJudul()); ?>" width="100">
                        </td>

                    </tr>

                <?php endforeach; ?>

            </tbody>

        </table>

    </div>


</body>

</html>