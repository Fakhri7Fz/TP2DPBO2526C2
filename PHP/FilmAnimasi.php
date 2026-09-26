<?php

class FilmAnimasi extends Film
{
    // =========================
    // ATTRIBUTE
    // =========================

    private $studioAnimasi;
    private $teknikAnimasi;
    private $pengisiSuara;
    private $foto_produk;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor dengan nilai default.
    public function __construct(
        $id = "",
        $judul = "",
        $tahunRilis = 0,
        $pencipta = "",
        $genre = "",
        $durasi = 0,
        $harga = 0,
        $studioAnimasi = "",
        $teknikAnimasi = "",
        $pengisiSuara = [],
        $foto_produk = ""
    ) {
        // Memanggil constructor dari parent class Film
        // untuk mengisi atribut yang diwariskan dari
        // KaryaSeni dan Film.
        parent::__construct(
            $id,
            $judul,
            $tahunRilis,
            $pencipta,
            $genre,
            $durasi,
            $harga
        );

        $this->studioAnimasi = $studioAnimasi;
        $this->teknikAnimasi = $teknikAnimasi;
        $this->pengisiSuara = $pengisiSuara;
        $this->foto_produk = $foto_produk;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter Studio Animasi
    public function setStudioAnimasi($studioAnimasi)
    {
        $this->studioAnimasi = $studioAnimasi;
    }

    public function getStudioAnimasi()
    {
        return $this->studioAnimasi;
    }

    // Setter dan getter Teknik Animasi
    public function setTeknikAnimasi($teknikAnimasi)
    {
        $this->teknikAnimasi = $teknikAnimasi;
    }

    public function getTeknikAnimasi()
    {
        return $this->teknikAnimasi;
    }

    // Setter dan getter Pengisi Suara
    public function setPengisiSuara($pengisiSuara)
    {
        $this->pengisiSuara = $pengisiSuara;
    }

    public function getPengisiSuara()
    {
        return $this->pengisiSuara;
    }

    // Setter dan getter Foto Produk
    // Atribut ini khusus digunakan pada versi PHP
    // sesuai dengan ketentuan tugas.
    public function setFotoProduk($foto_produk)
    {
        $this->foto_produk = $foto_produk;
    }

    public function getFotoProduk()
    {
        return $this->foto_produk;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi film animasi.
    public function tampilkan_info()
    {
        echo "ID              : " . $this->id . "<br>";
        echo "Judul           : " . $this->judul . "<br>";
        echo "Tahun Rilis     : " . $this->tahunRilis . "<br>";
        echo "Pencipta        : " . $this->pencipta . "<br>";
        echo "Genre           : " . $this->genre . "<br>";
        echo "Durasi          : " . $this->durasi . " menit<br>";
        echo "Harga           : Rp" . $this->harga . "<br>";
        echo "Studio Animasi  : " . $this->studioAnimasi . "<br>";
        echo "Teknik Animasi  : " . $this->teknikAnimasi . "<br>";

        echo "Pengisi Suara   : ";

        // Menampilkan seluruh pengisi suara.
        echo implode(", ", $this->pengisiSuara);
        echo "<br>";

        echo "Foto Produk     : " . $this->foto_produk . "<br>";
    }
}
?>