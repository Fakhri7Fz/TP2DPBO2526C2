<?php

class Film extends KaryaSeni
{
    // =========================
    // ATTRIBUTE
    // =========================

    protected $genre;
    protected $durasi;
    protected $harga;

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
        $harga = 0
    ) {
        // Memanggil constructor dari parent class KaryaSeni
        // untuk mengisi atribut yang diwariskan.
        parent::__construct(
            $id,
            $judul,
            $tahunRilis,
            $pencipta
        );

        $this->genre = $genre;
        $this->durasi = $durasi;
        $this->harga = $harga;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter Genre
    public function setGenre($genre)
    {
        $this->genre = $genre;
    }

    public function getGenre()
    {
        return $this->genre;
    }

    // Setter dan getter Durasi
    public function setDurasi($durasi)
    {
        if ($durasi >= 0 && $durasi <= 600) {
            $this->durasi = $durasi;
        } else if ($durasi < 0) {
            echo "Error: durasi tidak boleh negatif.";
        } else {
            echo "Error: durasi film tidak masuk akal. "
                . "Maksimal 600 menit.";
        }
    }

    public function getDurasi()
    {
        return $this->durasi;
    }

    // Setter dan getter Harga
    public function setHarga($harga)
    {
        if ($harga >= 0 && $harga <= 1000000) {
            $this->harga = $harga;
        } else if ($harga < 0) {
            echo "Error: harga tidak boleh negatif.";
        } else {
            echo "Error: harga tiket tidak masuk akal. "
                . "Maksimal Rp1000000.";
        }
    }

    public function getHarga()
    {
        return $this->harga;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi film.
    public function tampilkan_info()
    {
        echo "ID              : " . $this->id . "<br>";
        echo "Judul           : " . $this->judul . "<br>";
        echo "Tahun Rilis     : " . $this->tahunRilis . "<br>";
        echo "Pencipta        : " . $this->pencipta . "<br>";
        echo "Genre           : " . $this->genre . "<br>";
        echo "Durasi          : " . $this->durasi . " menit<br>";
        echo "Harga           : Rp" . $this->harga . "<br>";
    }
}
?>