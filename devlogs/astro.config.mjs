import { defineConfig } from "astro/config";
import vercel from "@astrojs/vercel/static";
import svelte from "@astrojs/svelte";
import tailwind from "@astrojs/tailwind";
import image from "@astrojs/image";
import remarkMermaid from "astro-diagram/remark-mermaid";
import prefetch from "@astrojs/prefetch";

export default defineConfig({
    output: "static",
    adapter: vercel(),
    integrations: [
        image({
            serviceEntryPoint: "@astrojs/image/sharp"
        }),
        svelte(),
        prefetch(),
        tailwind()
    ],
    markdown: {
        remarkPlugins: [remarkMermaid, "remark-math"],
        rehypePlugins: [
            [
                "rehype-katex",
                {
                    // Katex plugin options
                }
            ]
        ]
    }
});
