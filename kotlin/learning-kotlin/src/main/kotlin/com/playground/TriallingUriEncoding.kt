package com.playground

import java.net.URI
import java.net.URL
import java.net.URLDecoder
import java.net.URLEncoder

fun main(args: Array<String>) {
    val path: String = "https://localhost:12901/api/v1/cpi/status/83a03810-5966-4d8b-8532-74fbdb78a8ad"
    val uriEncoded = URI.create(URLEncoder.encode(path, "utf-8"))
    val uriNonEncoded = URI.create(path)
    println(uriEncoded)
    println(uriNonEncoded)

    var pathBeginning = "https://localhost:12901/"
    var pathEnd = "/api/v1/cpi/status/ 83a03810-5966-4d8b-8532-74fbdb78a8ad"
    val path1 = pathEnd.replace(" ", "%20")
    println("\nHere: ${URLDecoder.decode(path1, "utf-8")}")
    println(URI.create(pathBeginning + path1))


    val uri = URI.create(pathBeginning.trimEnd('/') + "/" + URLEncoder.encode(path1, "utf-8").trimStart('/'))
    println("\n$uri")
    println(URLDecoder.decode(uri.toString(), "utf-8"))


    val url = URL("https://localhost:12901/api/v1/cpi/status/83a03810-5966-4d8b-8532-74fbdb78a8ad")


    println("\n${url.toURI()}")
}