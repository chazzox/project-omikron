import { defineConfig } from "astro/config";
import vercel from "@astrojs/vercel/serverless";
import svelte from "@astrojs/svelte";
import tailwind from "@astrojs/tailwind";
import image from "@astrojs/image";

// https://astro.build/config
export default defineConfig({
    output: "server",
    adapter: vercel(),
    integrations: [
        image({
            serviceEntryPoint: "@astrojs/image/sharp"
        }),
        svelte(),
        tailwind()
    ]
});
