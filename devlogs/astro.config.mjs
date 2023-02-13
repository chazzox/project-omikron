import { defineConfig } from "astro/config";
import vercel from "@astrojs/vercel/static";
import svelte from "@astrojs/svelte";
import tailwind from "@astrojs/tailwind";
import image from "@astrojs/image";

import prefetch from "@astrojs/prefetch";
import mdx from "@astrojs/mdx";

export default defineConfig({
    output: "static",
    adapter: vercel(),
    integrations: [
        image({
            serviceEntryPoint: "@astrojs/image/sharp"
        }),
        svelte(),
        tailwind(),
        prefetch(),
        mdx()
    ]
});
